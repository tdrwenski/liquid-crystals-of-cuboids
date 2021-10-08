import argparse
import os
from argparse import ArgumentParser
import pandas as pd
from bokeh.plotting import figure, show
from bokeh.palettes import Dark2_5 as palette

TOLERANCE = 0.001


def parse_cli_arguments() -> argparse.Namespace:

    argument_parser = ArgumentParser("Order Parameter Plotter")
    argument_parser.add_argument("data_file", type=str, help="The data file to plot")
    argument_parser.add_argument("--guess", type=int, help="The first guess to start plotting from", default=0)
    return argument_parser.parse_args()


def find_lowest_energy(df: pd.DataFrame, first_guess: int) -> pd.DataFrame:

    selected_solutions = []
    for eta, df_eta in list(df.groupby("eta"))[::-1]:

        if selected_solutions:
            selected_solution = df_eta.loc[df_eta["freeEnergy"].idxmin()]
        else:
            selected_solution = df_eta.loc[df_eta["guess#"] == first_guess].iloc[0]

        if selected_solutions:

            if selected_solution["guess#"] != selected_solutions[-1]["guess#"]:
                selected_solution_previous_guess = df_eta[df_eta["guess#"] == selected_solutions[-1]["guess#"]].iloc[0]

                if selected_solution_previous_guess["freeEnergy"] - selected_solution["freeEnergy"] < TOLERANCE:
                    selected_solution = selected_solution_previous_guess

        selected_solutions.append(selected_solution)

    return pd.DataFrame(selected_solutions)


if __name__ == "__main__":

    cli_arguments = parse_cli_arguments()

    df = pd.read_csv(cli_arguments.data_file)

    df_solution = find_lowest_energy(df, first_guess=cli_arguments.guess)

    COL_X = "eta"
    COLS_Y = ["S", "U", "P", "F"]

    # Create figure
    fig = figure(title=os.path.basename(cli_arguments.data_file), x_axis_label=COL_X, y_axis_label="order parameters")

    for idx_coly, col_y in enumerate(COLS_Y):

        # Add line to the figure
        fig.line(
            x=df_solution[COL_X],
            y=df_solution[col_y],

            legend_label=f"{col_y}",
            color=palette[idx_coly % 5],
            line_width=2
        )

    show(fig)
