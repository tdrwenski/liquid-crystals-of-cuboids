#include "WignerMatrices.h"
#include <math.h>
#include <stdexcept>
#include <string>

//
// Generated from Mathematica
//
double smallWignerD(int L, int m, int n, double beta) {
    double smallD = 999.;

    // L=0
    if (L == 0) smallD = 1.;
    // L=1
    else if (L == 1) {
        if (m == -1) {
            if (n == -1)
                smallD = (1. + cos(beta)) / 2.;
            else if (n == 0)
                smallD = -sin(beta) / sqrt(2);
            else if (n == 1)
                smallD = (1. - cos(beta)) / 2.;
        } else if (m == 0) {
            if (n == -1)
                smallD = sin(beta) / sqrt(2);
            else if (n == 0)
                smallD = cos(beta);
            else if (n == 1)
                smallD = -sin(beta) / sqrt(2);
        } else if (m == 1) {
            if (n == -1)
                smallD = (1. - cos(beta)) / 2.;
            else if (n == 0)
                smallD = sin(beta) / sqrt(2);
            else if (n == 1)
                smallD = (1. + cos(beta)) / 2.;
        }
    }
    // L=2
    else if (L == 2) {
        if (m == -2) {
            if (n == -2)
                smallD = (1. + cos(beta)) * (1. + cos(beta)) / 4.;
            else if (n == -1)
                smallD = -sin(beta) * (1 + cos(beta)) / 2.;
            else if (n == 0)
                smallD = sin(beta) * sin(beta) * sqrt(3. / 8.);
            else if (n == 1)
                smallD = -sin(beta) * (1. - cos(beta)) / 2.;
            else if (n == 2)
                smallD = (1. - cos(beta)) * (1. - cos(beta)) / 4.;
        } else if (m == -1) {
            if (n == -2)
                smallD = sin(beta) * (1. + cos(beta)) / 2.;
            else if (n == -1)
                smallD = (2. * cos(beta) * cos(beta) + cos(beta) - 1.) / 2.;
            else if (n == 0)
                smallD = -sin(beta) * cos(beta) * sqrt(3. / 2.);
            else if (n == 1)
                smallD = -(2. * cos(beta) * cos(beta) - cos(beta) - 1.) / 2.;
            else if (n == 2)
                smallD = -sin(beta) * (1. - cos(beta)) / 2.;
        } else if (m == 0) {
            if (n == -2)
                smallD = sin(beta) * sin(beta) * sqrt(3. / 8.);
            else if (n == -1)
                smallD = sin(beta) * cos(beta) * sqrt(3. / 2.);
            else if (n == 0)
                smallD = 3. * cos(beta) * cos(beta) / 2. - 1. / 2.;
            else if (n == 1)
                smallD = -sin(beta) * cos(beta) * sqrt(3. / 2.);
            else if (n == 2)
                smallD = sin(beta) * sin(beta) * sqrt(3. / 8.);
        } else if (m == 1) {
            if (n == -2)
                smallD = sin(beta) * (1. - cos(beta)) / 2.;
            else if (n == -1)
                smallD = -(2. * cos(beta) * cos(beta) - cos(beta) - 1.) / 2.;
            else if (n == 0)
                smallD = sin(beta) * cos(beta) * sqrt(3. / 2.);
            else if (n == 1)
                smallD = (2. * cos(beta) * cos(beta) + cos(beta) - 1.) / 2.;
            else if (n == 2)
                smallD = -sin(beta) * (1. + cos(beta)) / 2.;
        } else if (m == 2) {
            if (n == -2)
                smallD = (1. - cos(beta)) * (1. - cos(beta)) / 4.;
            else if (n == -1)
                smallD = sin(beta) * (1 - cos(beta)) / 2.;
            else if (n == 0)
                smallD = sin(beta) * sin(beta) * sqrt(3. / 8.);
            else if (n == 1)
                smallD = sin(beta) * (1. + cos(beta)) / 2.;
            else if (n == 2)
                smallD = (1. + cos(beta)) * (1. + cos(beta)) / 4.;
        }
    }
    // L=3
    else if (L == 3) {
        if (m == -3) {
            if (n == -3)
                smallD = pow(cos(beta / 2.), 6);
            else if (n == -2)
                smallD = -(sqrt(6) * pow(cos(beta / 2.), 5) * sin(beta / 2.));
            else if (n == -1)
                smallD = sqrt(15) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = -2 * sqrt(5) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD = sqrt(15) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD = -(sqrt(6) * cos(beta / 2.) * pow(sin(beta / 2.), 5));
            else if (n == 3)
                smallD = pow(sin(beta / 2.), 6);
        } else if (m == -2) {
            if (n == -3)
                smallD = sqrt(6) * pow(cos(beta / 2.), 5) * sin(beta / 2.);
            else if (n == -2)
                smallD = (pow(cos(beta / 2.), 4) * (-4 + 6 * cos(beta))) / 2.;
            else if (n == -1)
                smallD = -(sqrt(2.5) * pow(cos(beta / 2.), 3) * (-2 + 6 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 0)
                smallD = sqrt(30) * pow(cos(beta / 2.), 2) * cos(beta) * pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = -(sqrt(2.5) * cos(beta / 2.) * (2 + 6 * cos(beta)) * pow(sin(beta / 2.), 3)) / 2.;
            else if (n == 2)
                smallD = ((4 + 6 * cos(beta)) * pow(sin(beta / 2.), 4)) / 2.;
            else if (n == 3)
                smallD = -(sqrt(6) * cos(beta / 2.) * pow(sin(beta / 2.), 5));
        } else if (m == -1) {
            if (n == -3)
                smallD = sqrt(15) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 2);
            else if (n == -2)
                smallD = (sqrt(2.5) * pow(cos(beta / 2.), 3) * (-2 + 6 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -1)
                smallD =
                    pow(cos(beta / 2.), 2) * (1 + 5 * (-1 + cos(beta)) + (15 * pow(-1 + cos(beta), 2)) / 4.);
            else if (n == 0)
                smallD = (-2 * cos(beta / 2.) *
                          (3 + (15 * (-1 + cos(beta))) / 2. + (15 * pow(-1 + cos(beta), 2)) / 4.) *
                          sin(beta / 2.)) /
                         sqrt(3);
            else if (n == 1)
                smallD =
                    (6 + 10 * (-1 + cos(beta)) + (15 * pow(-1 + cos(beta), 2)) / 4.) * pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = -(sqrt(2.5) * cos(beta / 2.) * (2 + 6 * cos(beta)) * pow(sin(beta / 2.), 3)) / 2.;
            else if (n == 3)
                smallD = sqrt(15) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 4);
        } else if (m == 0) {
            if (n == -3)
                smallD = 2 * sqrt(5) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 3);
            else if (n == -2)
                smallD = sqrt(30) * pow(cos(beta / 2.), 2) * cos(beta) * pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD = (2 * cos(beta / 2.) *
                          (3 + (15 * (-1 + cos(beta))) / 2. + (15 * pow(-1 + cos(beta), 2)) / 4.) *
                          sin(beta / 2.)) /
                         sqrt(3);
            else if (n == 0)
                smallD = (-3 * cos(beta) + 5 * pow(cos(beta), 3)) / 2.;
            else if (n == 1)
                smallD = (-2 * cos(beta / 2.) *
                          (3 + (15 * (-1 + cos(beta))) / 2. + (15 * pow(-1 + cos(beta), 2)) / 4.) *
                          sin(beta / 2.)) /
                         sqrt(3);
            else if (n == 2)
                smallD = sqrt(30) * pow(cos(beta / 2.), 2) * cos(beta) * pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = -2 * sqrt(5) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 3);
        } else if (m == 1) {
            if (n == -3)
                smallD = sqrt(15) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 4);
            else if (n == -2)
                smallD = (sqrt(2.5) * cos(beta / 2.) * (2 + 6 * cos(beta)) * pow(sin(beta / 2.), 3)) / 2.;
            else if (n == -1)
                smallD =
                    (6 + 10 * (-1 + cos(beta)) + (15 * pow(-1 + cos(beta), 2)) / 4.) * pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = (2 * cos(beta / 2.) *
                          (3 + (15 * (-1 + cos(beta))) / 2. + (15 * pow(-1 + cos(beta), 2)) / 4.) *
                          sin(beta / 2.)) /
                         sqrt(3);
            else if (n == 1)
                smallD =
                    pow(cos(beta / 2.), 2) * (1 + 5 * (-1 + cos(beta)) + (15 * pow(-1 + cos(beta), 2)) / 4.);
            else if (n == 2)
                smallD = -(sqrt(2.5) * pow(cos(beta / 2.), 3) * (-2 + 6 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 3)
                smallD = sqrt(15) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 2);
        } else if (m == 2) {
            if (n == -3)
                smallD = sqrt(6) * cos(beta / 2.) * pow(sin(beta / 2.), 5);
            else if (n == -2)
                smallD = ((4 + 6 * cos(beta)) * pow(sin(beta / 2.), 4)) / 2.;
            else if (n == -1)
                smallD = (sqrt(2.5) * cos(beta / 2.) * (2 + 6 * cos(beta)) * pow(sin(beta / 2.), 3)) / 2.;
            else if (n == 0)
                smallD = sqrt(30) * pow(cos(beta / 2.), 2) * cos(beta) * pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = (sqrt(2.5) * pow(cos(beta / 2.), 3) * (-2 + 6 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 2)
                smallD = (pow(cos(beta / 2.), 4) * (-4 + 6 * cos(beta))) / 2.;
            else if (n == 3)
                smallD = -(sqrt(6) * pow(cos(beta / 2.), 5) * sin(beta / 2.));
        } else if (m == 3) {
            if (n == -3)
                smallD = pow(sin(beta / 2.), 6);
            else if (n == -2)
                smallD = sqrt(6) * cos(beta / 2.) * pow(sin(beta / 2.), 5);
            else if (n == -1)
                smallD = sqrt(15) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = 2 * sqrt(5) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD = sqrt(15) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = sqrt(6) * pow(cos(beta / 2.), 5) * sin(beta / 2.);
            else if (n == 3)
                smallD = pow(cos(beta / 2.), 6);
        }
    }
    // L=4
    else if (L == 4) {
        if (m == -4) {
            if (n == -4)
                smallD = pow(cos(beta / 2.), 8);
            else if (n == -3)
                smallD = -2 * sqrt(2) * pow(cos(beta / 2.), 7) * sin(beta / 2.);
            else if (n == -2)
                smallD = 2 * sqrt(7) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD = -2 * sqrt(14) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 3);
            else if (n == 0)
                smallD = sqrt(70) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD = -2 * sqrt(14) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 5);
            else if (n == 2)
                smallD = 2 * sqrt(7) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 6);
            else if (n == 3)
                smallD = -2 * sqrt(2) * cos(beta / 2.) * pow(sin(beta / 2.), 7);
            else if (n == 4)
                smallD = pow(sin(beta / 2.), 8);
        } else if (m == -3) {
            if (n == -4)
                smallD = 2 * sqrt(2) * pow(cos(beta / 2.), 7) * sin(beta / 2.);
            else if (n == -3)
                smallD = (pow(cos(beta / 2.), 6) * (-6 + 8 * cos(beta))) / 2.;
            else if (n == -2)
                smallD = -(sqrt(3.5) * pow(cos(beta / 2.), 5) * (-4 + 8 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -1)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 4) * (-2 + 8 * cos(beta)) * pow(sin(beta / 2.), 2)) / 2.;
            else if (n == 0)
                smallD = -2 * sqrt(35) * pow(cos(beta / 2.), 3) * cos(beta) * pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 2) * (2 + 8 * cos(beta)) * pow(sin(beta / 2.), 4)) / 2.;
            else if (n == 2)
                smallD = -(sqrt(3.5) * cos(beta / 2.) * (4 + 8 * cos(beta)) * pow(sin(beta / 2.), 5)) / 2.;
            else if (n == 3)
                smallD = ((6 + 8 * cos(beta)) * pow(sin(beta / 2.), 6)) / 2.;
            else if (n == 4)
                smallD = -2 * sqrt(2) * cos(beta / 2.) * pow(sin(beta / 2.), 7);
        } else if (m == -2) {
            if (n == -4)
                smallD = 2 * sqrt(7) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 2);
            else if (n == -3)
                smallD = (sqrt(3.5) * pow(cos(beta / 2.), 5) * (-4 + 8 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -2)
                smallD = pow(cos(beta / 2.), 4) * (1 + 7 * (-1 + cos(beta)) + 7 * pow(-1 + cos(beta), 2));
            else if (n == -1)
                smallD = -(sqrt(2) * pow(cos(beta / 2.), 3) *
                           (3 + (21 * (-1 + cos(beta))) / 2. + 7 * pow(-1 + cos(beta), 2)) * sin(beta / 2.));
            else if (n == 0)
                smallD = sqrt(2.5) * pow(cos(beta / 2.), 2) *
                         (6 + 14 * (-1 + cos(beta)) + 7 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = -(sqrt(2) * cos(beta / 2.) *
                           (10 + (35 * (-1 + cos(beta))) / 2. + 7 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 3));
            else if (n == 2)
                smallD = (15 + 21 * (-1 + cos(beta)) + 7 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 4);
            else if (n == 3)
                smallD = -(sqrt(3.5) * cos(beta / 2.) * (4 + 8 * cos(beta)) * pow(sin(beta / 2.), 5)) / 2.;
            else if (n == 4)
                smallD = 2 * sqrt(7) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 6);
        } else if (m == -1) {
            if (n == -4)
                smallD = 2 * sqrt(14) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 3);
            else if (n == -3)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 4) * (-2 + 8 * cos(beta)) * pow(sin(beta / 2.), 2)) / 2.;
            else if (n == -2)
                smallD = sqrt(2) * pow(cos(beta / 2.), 3) *
                         (3 + (21 * (-1 + cos(beta))) / 2. + 7 * pow(-1 + cos(beta), 2)) * sin(beta / 2.);
            else if (n == -1)
                smallD =
                    pow(cos(beta / 2.), 2) * (1 + 9 * (-1 + cos(beta)) + (63 * pow(-1 + cos(beta), 2)) / 4. +
                                              7 * pow(-1 + cos(beta), 3));
            else if (n == 0)
                smallD =
                    -(sqrt(5) * cos(beta / 2.) *
                      (4 + 18 * (-1 + cos(beta)) + 21 * pow(-1 + cos(beta), 2) + 7 * pow(-1 + cos(beta), 3)) *
                      sin(beta / 2.)) /
                    2.;
            else if (n == 1)
                smallD = (10 + 30 * (-1 + cos(beta)) + (105 * pow(-1 + cos(beta), 2)) / 4. +
                          7 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = -(sqrt(2) * cos(beta / 2.) *
                           (10 + (35 * (-1 + cos(beta))) / 2. + 7 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 3));
            else if (n == 3)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 2) * (2 + 8 * cos(beta)) * pow(sin(beta / 2.), 4)) / 2.;
            else if (n == 4)
                smallD = -2 * sqrt(14) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 5);

        } else if (m == 0) {
            if (n == -4)
                smallD = sqrt(70) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 4);
            else if (n == -3)
                smallD = 2 * sqrt(35) * pow(cos(beta / 2.), 3) * cos(beta) * pow(sin(beta / 2.), 3);
            else if (n == -2)
                smallD = sqrt(2.5) * pow(cos(beta / 2.), 2) *
                         (6 + 14 * (-1 + cos(beta)) + 7 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD =
                    (sqrt(5) * cos(beta / 2.) *
                     (4 + 18 * (-1 + cos(beta)) + 21 * pow(-1 + cos(beta), 2) + 7 * pow(-1 + cos(beta), 3)) *
                     sin(beta / 2.)) /
                    2.;
            else if (n == 0)
                smallD = (3 - 30 * pow(cos(beta), 2) + 35 * pow(cos(beta), 4)) / 8.;
            else if (n == 1)
                smallD =
                    -(sqrt(5) * cos(beta / 2.) *
                      (4 + 18 * (-1 + cos(beta)) + 21 * pow(-1 + cos(beta), 2) + 7 * pow(-1 + cos(beta), 3)) *
                      sin(beta / 2.)) /
                    2.;
            else if (n == 2)
                smallD = sqrt(2.5) * pow(cos(beta / 2.), 2) *
                         (6 + 14 * (-1 + cos(beta)) + 7 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = -2 * sqrt(35) * pow(cos(beta / 2.), 3) * cos(beta) * pow(sin(beta / 2.), 3);
            else if (n == 4)
                smallD = sqrt(70) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 4);
        } else if (m == 1) {
            if (n == -4)
                smallD = 2 * sqrt(14) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 5);
            else if (n == -3)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 2) * (2 + 8 * cos(beta)) * pow(sin(beta / 2.), 4)) / 2.;
            else if (n == -2)
                smallD = sqrt(2) * cos(beta / 2.) *
                         (10 + (35 * (-1 + cos(beta))) / 2. + 7 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 3);
            else if (n == -1)
                smallD = (10 + 30 * (-1 + cos(beta)) + (105 * pow(-1 + cos(beta), 2)) / 4. +
                          7 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD =
                    (sqrt(5) * cos(beta / 2.) *
                     (4 + 18 * (-1 + cos(beta)) + 21 * pow(-1 + cos(beta), 2) + 7 * pow(-1 + cos(beta), 3)) *
                     sin(beta / 2.)) /
                    2.;
            else if (n == 1)
                smallD =
                    pow(cos(beta / 2.), 2) * (1 + 9 * (-1 + cos(beta)) + (63 * pow(-1 + cos(beta), 2)) / 4. +
                                              7 * pow(-1 + cos(beta), 3));
            else if (n == 2)
                smallD = -(sqrt(2) * pow(cos(beta / 2.), 3) *
                           (3 + (21 * (-1 + cos(beta))) / 2. + 7 * pow(-1 + cos(beta), 2)) * sin(beta / 2.));
            else if (n == 3)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 4) * (-2 + 8 * cos(beta)) * pow(sin(beta / 2.), 2)) / 2.;
            else if (n == 4)
                smallD = -2 * sqrt(14) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 3);
        } else if (m == 2) {
            if (n == -4)
                smallD = 2 * sqrt(7) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 6);
            else if (n == -3)
                smallD = (sqrt(3.5) * cos(beta / 2.) * (4 + 8 * cos(beta)) * pow(sin(beta / 2.), 5)) / 2.;
            else if (n == -2)
                smallD = (15 + 21 * (-1 + cos(beta)) + 7 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 4);
            else if (n == -1)
                smallD = sqrt(2) * cos(beta / 2.) *
                         (10 + (35 * (-1 + cos(beta))) / 2. + 7 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 3);
            else if (n == 0)
                smallD = sqrt(2.5) * pow(cos(beta / 2.), 2) *
                         (6 + 14 * (-1 + cos(beta)) + 7 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = sqrt(2) * pow(cos(beta / 2.), 3) *
                         (3 + (21 * (-1 + cos(beta))) / 2. + 7 * pow(-1 + cos(beta), 2)) * sin(beta / 2.);
            else if (n == 2)
                smallD = pow(cos(beta / 2.), 4) * (1 + 7 * (-1 + cos(beta)) + 7 * pow(-1 + cos(beta), 2));
            else if (n == 3)
                smallD = -(sqrt(3.5) * pow(cos(beta / 2.), 5) * (-4 + 8 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 4)
                smallD = 2 * sqrt(7) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 2);
        } else if (m == 3) {
            if (n == -4)
                smallD = 2 * sqrt(2) * cos(beta / 2.) * pow(sin(beta / 2.), 7);
            else if (n == -3)
                smallD = ((6 + 8 * cos(beta)) * pow(sin(beta / 2.), 6)) / 2.;
            else if (n == -2)
                smallD = (sqrt(3.5) * cos(beta / 2.) * (4 + 8 * cos(beta)) * pow(sin(beta / 2.), 5)) / 2.;
            else if (n == -1)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 2) * (2 + 8 * cos(beta)) * pow(sin(beta / 2.), 4)) / 2.;
            else if (n == 0)
                smallD = 2 * sqrt(35) * pow(cos(beta / 2.), 3) * cos(beta) * pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 4) * (-2 + 8 * cos(beta)) * pow(sin(beta / 2.), 2)) / 2.;
            else if (n == 2)
                smallD = (sqrt(3.5) * pow(cos(beta / 2.), 5) * (-4 + 8 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 3)
                smallD = (pow(cos(beta / 2.), 6) * (-6 + 8 * cos(beta))) / 2.;
            else if (n == 4)
                smallD = -2 * sqrt(2) * pow(cos(beta / 2.), 7) * sin(beta / 2.);
        } else if (m == 4) {
            if (n == -4)
                smallD = pow(sin(beta / 2.), 8);
            else if (n == -3)
                smallD = 2 * sqrt(2) * cos(beta / 2.) * pow(sin(beta / 2.), 7);
            else if (n == -2)
                smallD = 2 * sqrt(7) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 6);
            else if (n == -1)
                smallD = 2 * sqrt(14) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 5);
            else if (n == 0)
                smallD = sqrt(70) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD = 2 * sqrt(14) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 3);
            else if (n == 2)
                smallD = 2 * sqrt(7) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = 2 * sqrt(2) * pow(cos(beta / 2.), 7) * sin(beta / 2.);
            else if (n == 4)
                smallD = pow(cos(beta / 2.), 8);
        }
    }
    // L=5
    else if (L == 5) {
        if (m == -5) {
            if (n == -5)
                smallD = pow(cos(beta / 2.), 10);
            else if (n == -4)
                smallD = -(sqrt(10) * pow(cos(beta / 2.), 9) * sin(beta / 2.));
            else if (n == -3)
                smallD = 3 * sqrt(5) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 2);
            else if (n == -2)
                smallD = -2 * sqrt(30) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 3);
            else if (n == -1)
                smallD = sqrt(210) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = -6 * sqrt(7) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 5);
            else if (n == 1)
                smallD = sqrt(210) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 6);
            else if (n == 2)
                smallD = -2 * sqrt(30) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 7);
            else if (n == 3)
                smallD = 3 * sqrt(5) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 8);
            else if (n == 4)
                smallD = -(sqrt(10) * cos(beta / 2.) * pow(sin(beta / 2.), 9));
            else if (n == 5)
                smallD = pow(sin(beta / 2.), 10);
        } else if (m == -4) {
            if (n == -5)
                smallD = sqrt(10) * pow(cos(beta / 2.), 9) * sin(beta / 2.);
            else if (n == -4)
                smallD = (pow(cos(beta / 2.), 8) * (-8 + 10 * cos(beta))) / 2.;
            else if (n == -3)
                smallD =
                    (-3 * pow(cos(beta / 2.), 7) * (-6 + 10 * cos(beta)) * sin(beta / 2.)) / (2. * sqrt(2));
            else if (n == -2)
                smallD = sqrt(3) * pow(cos(beta / 2.), 6) * (-4 + 10 * cos(beta)) * pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD =
                    -(sqrt(21) * pow(cos(beta / 2.), 5) * (-2 + 10 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    2.;
            else if (n == 0)
                smallD = 3 * sqrt(70) * pow(cos(beta / 2.), 4) * cos(beta) * pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD =
                    -(sqrt(21) * pow(cos(beta / 2.), 3) * (2 + 10 * cos(beta)) * pow(sin(beta / 2.), 5)) / 2.;
            else if (n == 2)
                smallD = sqrt(3) * pow(cos(beta / 2.), 2) * (4 + 10 * cos(beta)) * pow(sin(beta / 2.), 6);
            else if (n == 3)
                smallD =
                    (-3 * cos(beta / 2.) * (6 + 10 * cos(beta)) * pow(sin(beta / 2.), 7)) / (2. * sqrt(2));
            else if (n == 4)
                smallD = ((8 + 10 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == 5)
                smallD = -(sqrt(10) * cos(beta / 2.) * pow(sin(beta / 2.), 9));
        } else if (m == -3) {
            if (n == -5)
                smallD = 3 * sqrt(5) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 2);
            else if (n == -4)
                smallD =
                    (3 * pow(cos(beta / 2.), 7) * (-6 + 10 * cos(beta)) * sin(beta / 2.)) / (2. * sqrt(2));
            else if (n == -3)
                smallD =
                    pow(cos(beta / 2.), 6) * (1 + 9 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.);
            else if (n == -2)
                smallD = -2 * sqrt(0.6666666666666666) * pow(cos(beta / 2.), 5) *
                         (3 + (27 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         sin(beta / 2.);
            else if (n == -1)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 4) *
                         (6 + 18 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = -2 * sqrt(1.4) * pow(cos(beta / 2.), 3) *
                         (10 + (45 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 2) *
                         (15 + 27 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD = -2 * sqrt(0.6666666666666666) * cos(beta / 2.) *
                         (21 + (63 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 3)
                smallD = (28 + 36 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 4)
                smallD =
                    (-3 * cos(beta / 2.) * (6 + 10 * cos(beta)) * pow(sin(beta / 2.), 7)) / (2. * sqrt(2));
            else if (n == 5)
                smallD = 3 * sqrt(5) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 8);
        } else if (m == -2) {
            if (n == -5)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 3);
            else if (n == -4)
                smallD = sqrt(3) * pow(cos(beta / 2.), 6) * (-4 + 10 * cos(beta)) * pow(sin(beta / 2.), 2);
            else if (n == -3)
                smallD = 2 * sqrt(0.6666666666666666) * pow(cos(beta / 2.), 5) *
                         (3 + (27 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         sin(beta / 2.);
            else if (n == -2)
                smallD = pow(cos(beta / 2.), 4) * (1 + 12 * (-1 + cos(beta)) + 27 * pow(-1 + cos(beta), 2) +
                                                   15 * pow(-1 + cos(beta), 3));
            else if (n == -1)
                smallD = -(sqrt(7) * pow(cos(beta / 2.), 3) *
                           (4 + 24 * (-1 + cos(beta)) + 36 * pow(-1 + cos(beta), 2) +
                            15 * pow(-1 + cos(beta), 3)) *
                           sin(beta / 2.)) /
                         2.;
            else if (n == 0)
                smallD =
                    sqrt(2.1) * pow(cos(beta / 2.), 2) *
                    (10 + 40 * (-1 + cos(beta)) + 45 * pow(-1 + cos(beta), 2) + 15 * pow(-1 + cos(beta), 3)) *
                    pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = -(sqrt(7) * cos(beta / 2.) *
                           (20 + 60 * (-1 + cos(beta)) + 54 * pow(-1 + cos(beta), 2) +
                            15 * pow(-1 + cos(beta), 3)) *
                           pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 2)
                smallD =
                    (35 + 84 * (-1 + cos(beta)) + 63 * pow(-1 + cos(beta), 2) + 15 * pow(-1 + cos(beta), 3)) *
                    pow(sin(beta / 2.), 4);
            else if (n == 3)
                smallD = -2 * sqrt(0.6666666666666666) * cos(beta / 2.) *
                         (21 + (63 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 4)
                smallD = sqrt(3) * pow(cos(beta / 2.), 2) * (4 + 10 * cos(beta)) * pow(sin(beta / 2.), 6);
            else if (n == 5)
                smallD = -2 * sqrt(30) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 7);
        } else if (m == -1) {
            if (n == -5)
                smallD = sqrt(210) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 4);
            else if (n == -4)
                smallD =
                    (sqrt(21) * pow(cos(beta / 2.), 5) * (-2 + 10 * cos(beta)) * pow(sin(beta / 2.), 3)) / 2.;
            else if (n == -3)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 4) *
                         (6 + 18 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -2)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 3) *
                     (4 + 24 * (-1 + cos(beta)) + 36 * pow(-1 + cos(beta), 2) + 15 * pow(-1 + cos(beta), 3)) *
                     sin(beta / 2.)) /
                    2.;
            else if (n == -1)
                smallD = pow(cos(beta / 2.), 2) *
                         (1 + 14 * (-1 + cos(beta)) + 42 * pow(-1 + cos(beta), 2) +
                          42 * pow(-1 + cos(beta), 3) + (105 * pow(-1 + cos(beta), 4)) / 8.);
            else if (n == 0)
                smallD = -(sqrt(1.2) * cos(beta / 2.) *
                           (5 + 35 * (-1 + cos(beta)) + 70 * pow(-1 + cos(beta), 2) +
                            (105 * pow(-1 + cos(beta), 3)) / 2. + (105 * pow(-1 + cos(beta), 4)) / 8.) *
                           sin(beta / 2.));
            else if (n == 1)
                smallD = (15 + 70 * (-1 + cos(beta)) + 105 * pow(-1 + cos(beta), 2) +
                          63 * pow(-1 + cos(beta), 3) + (105 * pow(-1 + cos(beta), 4)) / 8.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = -(sqrt(7) * cos(beta / 2.) *
                           (20 + 60 * (-1 + cos(beta)) + 54 * pow(-1 + cos(beta), 2) +
                            15 * pow(-1 + cos(beta), 3)) *
                           pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 3)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 2) *
                         (15 + 27 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 4)
                smallD =
                    -(sqrt(21) * pow(cos(beta / 2.), 3) * (2 + 10 * cos(beta)) * pow(sin(beta / 2.), 5)) / 2.;
            else if (n == 5)
                smallD = sqrt(210) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 6);
        } else if (m == 0) {
            if (n == -5)
                smallD = 6 * sqrt(7) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 5);
            else if (n == -4)
                smallD = 3 * sqrt(70) * pow(cos(beta / 2.), 4) * cos(beta) * pow(sin(beta / 2.), 4);
            else if (n == -3)
                smallD = 2 * sqrt(1.4) * pow(cos(beta / 2.), 3) *
                         (10 + (45 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -2)
                smallD =
                    sqrt(2.1) * pow(cos(beta / 2.), 2) *
                    (10 + 40 * (-1 + cos(beta)) + 45 * pow(-1 + cos(beta), 2) + 15 * pow(-1 + cos(beta), 3)) *
                    pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD = sqrt(1.2) * cos(beta / 2.) *
                         (5 + 35 * (-1 + cos(beta)) + 70 * pow(-1 + cos(beta), 2) +
                          (105 * pow(-1 + cos(beta), 3)) / 2. + (105 * pow(-1 + cos(beta), 4)) / 8.) *
                         sin(beta / 2.);
            else if (n == 0)
                smallD = (15 * cos(beta) - 70 * pow(cos(beta), 3) + 63 * pow(cos(beta), 5)) / 8.;
            else if (n == 1)
                smallD = -(sqrt(1.2) * cos(beta / 2.) *
                           (5 + 35 * (-1 + cos(beta)) + 70 * pow(-1 + cos(beta), 2) +
                            (105 * pow(-1 + cos(beta), 3)) / 2. + (105 * pow(-1 + cos(beta), 4)) / 8.) *
                           sin(beta / 2.));
            else if (n == 2)
                smallD =
                    sqrt(2.1) * pow(cos(beta / 2.), 2) *
                    (10 + 40 * (-1 + cos(beta)) + 45 * pow(-1 + cos(beta), 2) + 15 * pow(-1 + cos(beta), 3)) *
                    pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = -2 * sqrt(1.4) * pow(cos(beta / 2.), 3) *
                         (10 + (45 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 4)
                smallD = 3 * sqrt(70) * pow(cos(beta / 2.), 4) * cos(beta) * pow(sin(beta / 2.), 4);
            else if (n == 5)
                smallD = -6 * sqrt(7) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 5);
        } else if (m == 1) {
            if (n == -5)
                smallD = sqrt(210) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 6);
            else if (n == -4)
                smallD =
                    (sqrt(21) * pow(cos(beta / 2.), 3) * (2 + 10 * cos(beta)) * pow(sin(beta / 2.), 5)) / 2.;
            else if (n == -3)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 2) *
                         (15 + 27 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -2)
                smallD = (sqrt(7) * cos(beta / 2.) *
                          (20 + 60 * (-1 + cos(beta)) + 54 * pow(-1 + cos(beta), 2) +
                           15 * pow(-1 + cos(beta), 3)) *
                          pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == -1)
                smallD = (15 + 70 * (-1 + cos(beta)) + 105 * pow(-1 + cos(beta), 2) +
                          63 * pow(-1 + cos(beta), 3) + (105 * pow(-1 + cos(beta), 4)) / 8.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = sqrt(1.2) * cos(beta / 2.) *
                         (5 + 35 * (-1 + cos(beta)) + 70 * pow(-1 + cos(beta), 2) +
                          (105 * pow(-1 + cos(beta), 3)) / 2. + (105 * pow(-1 + cos(beta), 4)) / 8.) *
                         sin(beta / 2.);
            else if (n == 1)
                smallD = pow(cos(beta / 2.), 2) *
                         (1 + 14 * (-1 + cos(beta)) + 42 * pow(-1 + cos(beta), 2) +
                          42 * pow(-1 + cos(beta), 3) + (105 * pow(-1 + cos(beta), 4)) / 8.);
            else if (n == 2)
                smallD = -(sqrt(7) * pow(cos(beta / 2.), 3) *
                           (4 + 24 * (-1 + cos(beta)) + 36 * pow(-1 + cos(beta), 2) +
                            15 * pow(-1 + cos(beta), 3)) *
                           sin(beta / 2.)) /
                         2.;
            else if (n == 3)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 4) *
                         (6 + 18 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 4)
                smallD =
                    -(sqrt(21) * pow(cos(beta / 2.), 5) * (-2 + 10 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    2.;
            else if (n == 5)
                smallD = sqrt(210) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 4);
        } else if (m == 2) {
            if (n == -5)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 7);
            else if (n == -4)
                smallD = sqrt(3) * pow(cos(beta / 2.), 2) * (4 + 10 * cos(beta)) * pow(sin(beta / 2.), 6);
            else if (n == -3)
                smallD = 2 * sqrt(0.6666666666666666) * cos(beta / 2.) *
                         (21 + (63 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -2)
                smallD =
                    (35 + 84 * (-1 + cos(beta)) + 63 * pow(-1 + cos(beta), 2) + 15 * pow(-1 + cos(beta), 3)) *
                    pow(sin(beta / 2.), 4);
            else if (n == -1)
                smallD = (sqrt(7) * cos(beta / 2.) *
                          (20 + 60 * (-1 + cos(beta)) + 54 * pow(-1 + cos(beta), 2) +
                           15 * pow(-1 + cos(beta), 3)) *
                          pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 0)
                smallD =
                    sqrt(2.1) * pow(cos(beta / 2.), 2) *
                    (10 + 40 * (-1 + cos(beta)) + 45 * pow(-1 + cos(beta), 2) + 15 * pow(-1 + cos(beta), 3)) *
                    pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD =
                    (sqrt(7) * pow(cos(beta / 2.), 3) *
                     (4 + 24 * (-1 + cos(beta)) + 36 * pow(-1 + cos(beta), 2) + 15 * pow(-1 + cos(beta), 3)) *
                     sin(beta / 2.)) /
                    2.;
            else if (n == 2)
                smallD = pow(cos(beta / 2.), 4) * (1 + 12 * (-1 + cos(beta)) + 27 * pow(-1 + cos(beta), 2) +
                                                   15 * pow(-1 + cos(beta), 3));
            else if (n == 3)
                smallD = -2 * sqrt(0.6666666666666666) * pow(cos(beta / 2.), 5) *
                         (3 + (27 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         sin(beta / 2.);
            else if (n == 4)
                smallD = sqrt(3) * pow(cos(beta / 2.), 6) * (-4 + 10 * cos(beta)) * pow(sin(beta / 2.), 2);
            else if (n == 5)
                smallD = -2 * sqrt(30) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 3);
        } else if (m == 3) {
            if (n == -5)
                smallD = 3 * sqrt(5) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 8);
            else if (n == -4)
                smallD =
                    (3 * cos(beta / 2.) * (6 + 10 * cos(beta)) * pow(sin(beta / 2.), 7)) / (2. * sqrt(2));
            else if (n == -3)
                smallD = (28 + 36 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -2)
                smallD = 2 * sqrt(0.6666666666666666) * cos(beta / 2.) *
                         (21 + (63 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -1)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 2) *
                         (15 + 27 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = 2 * sqrt(1.4) * pow(cos(beta / 2.), 3) *
                         (10 + (45 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 4) *
                         (6 + 18 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = 2 * sqrt(0.6666666666666666) * pow(cos(beta / 2.), 5) *
                         (3 + (27 * (-1 + cos(beta))) / 2. + (45 * pow(-1 + cos(beta), 2)) / 4.) *
                         sin(beta / 2.);
            else if (n == 3)
                smallD =
                    pow(cos(beta / 2.), 6) * (1 + 9 * (-1 + cos(beta)) + (45 * pow(-1 + cos(beta), 2)) / 4.);
            else if (n == 4)
                smallD =
                    (-3 * pow(cos(beta / 2.), 7) * (-6 + 10 * cos(beta)) * sin(beta / 2.)) / (2. * sqrt(2));
            else if (n == 5)
                smallD = 3 * sqrt(5) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 2);
        } else if (m == 4) {
            if (n == -5)
                smallD = sqrt(10) * cos(beta / 2.) * pow(sin(beta / 2.), 9);
            else if (n == -4)
                smallD = ((8 + 10 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == -3)
                smallD =
                    (3 * cos(beta / 2.) * (6 + 10 * cos(beta)) * pow(sin(beta / 2.), 7)) / (2. * sqrt(2));
            else if (n == -2)
                smallD = sqrt(3) * pow(cos(beta / 2.), 2) * (4 + 10 * cos(beta)) * pow(sin(beta / 2.), 6);
            else if (n == -1)
                smallD =
                    (sqrt(21) * pow(cos(beta / 2.), 3) * (2 + 10 * cos(beta)) * pow(sin(beta / 2.), 5)) / 2.;
            else if (n == 0)
                smallD = 3 * sqrt(70) * pow(cos(beta / 2.), 4) * cos(beta) * pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD =
                    (sqrt(21) * pow(cos(beta / 2.), 5) * (-2 + 10 * cos(beta)) * pow(sin(beta / 2.), 3)) / 2.;
            else if (n == 2)
                smallD = sqrt(3) * pow(cos(beta / 2.), 6) * (-4 + 10 * cos(beta)) * pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD =
                    (3 * pow(cos(beta / 2.), 7) * (-6 + 10 * cos(beta)) * sin(beta / 2.)) / (2. * sqrt(2));
            else if (n == 4)
                smallD = (pow(cos(beta / 2.), 8) * (-8 + 10 * cos(beta))) / 2.;
            else if (n == 5)
                smallD = -(sqrt(10) * pow(cos(beta / 2.), 9) * sin(beta / 2.));
        } else if (m == 5) {
            if (n == -5)
                smallD = pow(sin(beta / 2.), 10);
            else if (n == -4)
                smallD = sqrt(10) * cos(beta / 2.) * pow(sin(beta / 2.), 9);
            else if (n == -3)
                smallD = 3 * sqrt(5) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 8);
            else if (n == -2)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 7);
            else if (n == -1)
                smallD = sqrt(210) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 6);
            else if (n == 0)
                smallD = 6 * sqrt(7) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 5);
            else if (n == 1)
                smallD = sqrt(210) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 3);
            else if (n == 3)
                smallD = 3 * sqrt(5) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 2);
            else if (n == 4)
                smallD = sqrt(10) * pow(cos(beta / 2.), 9) * sin(beta / 2.);
            else if (n == 5)
                smallD = pow(cos(beta / 2.), 10);
        }
    }
    // L = 6
    else if (L == 6) {
        if (m == -6) {
            if (n == -6)
                smallD = pow(cos(beta / 2.), 12);
            else if (n == -5)
                smallD = -2 * sqrt(3) * pow(cos(beta / 2.), 11) * sin(beta / 2.);
            else if (n == -4)
                smallD = sqrt(66) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 2);
            else if (n == -3)
                smallD = -2 * sqrt(55) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 3);
            else if (n == -2)
                smallD = 3 * sqrt(55) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 4);
            else if (n == -1)
                smallD = -6 * sqrt(22) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 5);
            else if (n == 0)
                smallD = 2 * sqrt(231) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 6);
            else if (n == 1)
                smallD = -6 * sqrt(22) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 7);
            else if (n == 2)
                smallD = 3 * sqrt(55) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 8);
            else if (n == 3)
                smallD = -2 * sqrt(55) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 9);
            else if (n == 4)
                smallD = sqrt(66) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 10);
            else if (n == 5)
                smallD = -2 * sqrt(3) * cos(beta / 2.) * pow(sin(beta / 2.), 11);
            else if (n == 6)
                smallD = pow(sin(beta / 2.), 12);
        } else if (m == -5) {
            if (n == -6)
                smallD = 2 * sqrt(3) * pow(cos(beta / 2.), 11) * sin(beta / 2.);
            else if (n == -5)
                smallD = (pow(cos(beta / 2.), 10) * (-10 + 12 * cos(beta))) / 2.;
            else if (n == -4)
                smallD = -(sqrt(5.5) * pow(cos(beta / 2.), 9) * (-8 + 12 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -3)
                smallD = (sqrt(18.333333333333332) * pow(cos(beta / 2.), 8) * (-6 + 12 * cos(beta)) *
                          pow(sin(beta / 2.), 2)) /
                         2.;
            else if (n == -2)
                smallD =
                    -(sqrt(165) * pow(cos(beta / 2.), 7) * (-4 + 12 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    4.;
            else if (n == -1)
                smallD = sqrt(16.5) * pow(cos(beta / 2.), 6) * (-2 + 12 * cos(beta)) * pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = -6 * sqrt(77) * pow(cos(beta / 2.), 5) * cos(beta) * pow(sin(beta / 2.), 5);
            else if (n == 1)
                smallD = sqrt(16.5) * pow(cos(beta / 2.), 4) * (2 + 12 * cos(beta)) * pow(sin(beta / 2.), 6);
            else if (n == 2)
                smallD =
                    -(sqrt(165) * pow(cos(beta / 2.), 3) * (4 + 12 * cos(beta)) * pow(sin(beta / 2.), 7)) /
                    4.;
            else if (n == 3)
                smallD = (sqrt(18.333333333333332) * pow(cos(beta / 2.), 2) * (6 + 12 * cos(beta)) *
                          pow(sin(beta / 2.), 8)) /
                         2.;
            else if (n == 4)
                smallD = -(sqrt(5.5) * cos(beta / 2.) * (8 + 12 * cos(beta)) * pow(sin(beta / 2.), 9)) / 2.;
            else if (n == 5)
                smallD = ((10 + 12 * cos(beta)) * pow(sin(beta / 2.), 10)) / 2.;
            else if (n == 6)
                smallD = -2 * sqrt(3) * cos(beta / 2.) * pow(sin(beta / 2.), 11);
        } else if (m == -4) {
            if (n == -6)
                smallD = sqrt(66) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 2);
            else if (n == -5)
                smallD = (sqrt(5.5) * pow(cos(beta / 2.), 9) * (-8 + 12 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -4)
                smallD =
                    pow(cos(beta / 2.), 8) * (1 + 11 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.);
            else if (n == -3)
                smallD = -(sqrt(3.3333333333333335) * pow(cos(beta / 2.), 7) *
                           (3 + (33 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                           sin(beta / 2.));
            else if (n == -2)
                smallD = sqrt(7.5) * pow(cos(beta / 2.), 6) *
                         (6 + 22 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD = -2 * sqrt(3) * pow(cos(beta / 2.), 5) *
                         (10 + (55 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 0)
                smallD = sqrt(14) * pow(cos(beta / 2.), 4) *
                         (15 + 33 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD = -2 * sqrt(3) * pow(cos(beta / 2.), 3) *
                         (21 + (77 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 2)
                smallD = sqrt(7.5) * pow(cos(beta / 2.), 2) *
                         (28 + 44 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 3)
                smallD = -(sqrt(3.3333333333333335) * cos(beta / 2.) *
                           (36 + (99 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                           pow(sin(beta / 2.), 7));
            else if (n == 4)
                smallD = (45 + 55 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 8);
            else if (n == 5)
                smallD = -(sqrt(5.5) * cos(beta / 2.) * (8 + 12 * cos(beta)) * pow(sin(beta / 2.), 9)) / 2.;
            else if (n == 6)
                smallD = sqrt(66) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 10);
        } else if (m == -3) {
            if (n == -6)
                smallD = 2 * sqrt(55) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 3);
            else if (n == -5)
                smallD = (sqrt(18.333333333333332) * pow(cos(beta / 2.), 8) * (-6 + 12 * cos(beta)) *
                          pow(sin(beta / 2.), 2)) /
                         2.;
            else if (n == -4)
                smallD = sqrt(3.3333333333333335) * pow(cos(beta / 2.), 7) *
                         (3 + (33 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         sin(beta / 2.);
            else if (n == -3)
                smallD = pow(cos(beta / 2.), 6) *
                         (1 + 15 * (-1 + cos(beta)) + (165 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.);
            else if (n == -2)
                smallD = (-3 * pow(cos(beta / 2.), 5) *
                          (4 + 30 * (-1 + cos(beta)) + 55 * pow(-1 + cos(beta), 2) +
                           (55 * pow(-1 + cos(beta), 3)) / 2.) *
                          sin(beta / 2.)) /
                         2.;
            else if (n == -1)
                smallD = 3 * sqrt(0.4) * pow(cos(beta / 2.), 4) *
                         (10 + 50 * (-1 + cos(beta)) + (275 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = -(sqrt(4.2) * pow(cos(beta / 2.), 3) *
                           (20 + 75 * (-1 + cos(beta)) + (165 * pow(-1 + cos(beta), 2)) / 2. +
                            (55 * pow(-1 + cos(beta), 3)) / 2.) *
                           pow(sin(beta / 2.), 3));
            else if (n == 1)
                smallD = 3 * sqrt(0.4) * pow(cos(beta / 2.), 2) *
                         (35 + 105 * (-1 + cos(beta)) + (385 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD = (-3 * cos(beta / 2.) *
                          (56 + 140 * (-1 + cos(beta)) + 110 * pow(-1 + cos(beta), 2) +
                           (55 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == 3)
                smallD = (84 + 180 * (-1 + cos(beta)) + (495 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 4)
                smallD = -(sqrt(3.3333333333333335) * cos(beta / 2.) *
                           (36 + (99 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                           pow(sin(beta / 2.), 7));
            else if (n == 5)
                smallD = (sqrt(18.333333333333332) * pow(cos(beta / 2.), 2) * (6 + 12 * cos(beta)) *
                          pow(sin(beta / 2.), 8)) /
                         2.;
            else if (n == 6)
                smallD = -2 * sqrt(55) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 9);
        } else if (m == -2) {
            if (n == -6)
                smallD = 3 * sqrt(55) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 4);
            else if (n == -5)
                smallD =
                    (sqrt(165) * pow(cos(beta / 2.), 7) * (-4 + 12 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    4.;
            else if (n == -4)
                smallD = sqrt(7.5) * pow(cos(beta / 2.), 6) *
                         (6 + 22 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -3)
                smallD = (3 * pow(cos(beta / 2.), 5) *
                          (4 + 30 * (-1 + cos(beta)) + 55 * pow(-1 + cos(beta), 2) +
                           (55 * pow(-1 + cos(beta), 3)) / 2.) *
                          sin(beta / 2.)) /
                         2.;
            else if (n == -2)
                smallD = pow(cos(beta / 2.), 4) *
                         (1 + 18 * (-1 + cos(beta)) + (135 * pow(-1 + cos(beta), 2)) / 2. +
                          (165 * pow(-1 + cos(beta), 3)) / 2. + (495 * pow(-1 + cos(beta), 4)) / 16.);
            else if (n == -1)
                smallD = -2 * sqrt(0.4) * pow(cos(beta / 2.), 3) *
                         (5 + 45 * (-1 + cos(beta)) + (225 * pow(-1 + cos(beta), 2)) / 2. +
                          (825 * pow(-1 + cos(beta), 3)) / 8. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         sin(beta / 2.);
            else if (n == 0)
                smallD = 2 * sqrt(0.4666666666666667) * pow(cos(beta / 2.), 2) *
                         (15 + 90 * (-1 + cos(beta)) + (675 * pow(-1 + cos(beta), 2)) / 4. +
                          (495 * pow(-1 + cos(beta), 3)) / 4. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = -2 * sqrt(0.4) * cos(beta / 2.) *
                         (35 + (315 * (-1 + cos(beta))) / 2. + (945 * pow(-1 + cos(beta), 2)) / 4. +
                          (1155 * pow(-1 + cos(beta), 3)) / 8. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 2)
                smallD = (70 + 252 * (-1 + cos(beta)) + 315 * pow(-1 + cos(beta), 2) +
                          165 * pow(-1 + cos(beta), 3) + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 3)
                smallD = (-3 * cos(beta / 2.) *
                          (56 + 140 * (-1 + cos(beta)) + 110 * pow(-1 + cos(beta), 2) +
                           (55 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == 4)
                smallD = sqrt(7.5) * pow(cos(beta / 2.), 2) *
                         (28 + 44 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 5)
                smallD =
                    -(sqrt(165) * pow(cos(beta / 2.), 3) * (4 + 12 * cos(beta)) * pow(sin(beta / 2.), 7)) /
                    4.;
            else if (n == 6)
                smallD = 3 * sqrt(55) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 8);
        } else if (m == -1) {
            if (n == -6)
                smallD = 6 * sqrt(22) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 5);
            else if (n == -5)
                smallD = sqrt(16.5) * pow(cos(beta / 2.), 6) * (-2 + 12 * cos(beta)) * pow(sin(beta / 2.), 4);
            else if (n == -4)
                smallD = 2 * sqrt(3) * pow(cos(beta / 2.), 5) *
                         (10 + (55 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -3)
                smallD = 3 * sqrt(0.4) * pow(cos(beta / 2.), 4) *
                         (10 + 50 * (-1 + cos(beta)) + (275 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -2)
                smallD = 2 * sqrt(0.4) * pow(cos(beta / 2.), 3) *
                         (5 + 45 * (-1 + cos(beta)) + (225 * pow(-1 + cos(beta), 2)) / 2. +
                          (825 * pow(-1 + cos(beta), 3)) / 8. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         sin(beta / 2.);
            else if (n == -1)
                smallD =
                    pow(cos(beta / 2.), 2) *
                    (1 + 20 * (-1 + cos(beta)) + 90 * pow(-1 + cos(beta), 2) + 150 * pow(-1 + cos(beta), 3) +
                     (825 * pow(-1 + cos(beta), 4)) / 8. + (99 * pow(-1 + cos(beta), 5)) / 4.);
            else if (n == 0)
                smallD = -(sqrt(1.1666666666666667) * cos(beta / 2.) *
                           (6 + 60 * (-1 + cos(beta)) + 180 * pow(-1 + cos(beta), 2) +
                            225 * pow(-1 + cos(beta), 3) + (495 * pow(-1 + cos(beta), 4)) / 4. +
                            (99 * pow(-1 + cos(beta), 5)) / 4.) *
                           sin(beta / 2.));
            else if (n == 1)
                smallD = (21 + 140 * (-1 + cos(beta)) + 315 * pow(-1 + cos(beta), 2) +
                          315 * pow(-1 + cos(beta), 3) + (1155 * pow(-1 + cos(beta), 4)) / 8. +
                          (99 * pow(-1 + cos(beta), 5)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = -2 * sqrt(0.4) * cos(beta / 2.) *
                         (35 + (315 * (-1 + cos(beta))) / 2. + (945 * pow(-1 + cos(beta), 2)) / 4. +
                          (1155 * pow(-1 + cos(beta), 3)) / 8. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 3)
                smallD = 3 * sqrt(0.4) * pow(cos(beta / 2.), 2) *
                         (35 + 105 * (-1 + cos(beta)) + (385 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 4)
                smallD = -2 * sqrt(3) * pow(cos(beta / 2.), 3) *
                         (21 + (77 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 5)
                smallD = sqrt(16.5) * pow(cos(beta / 2.), 4) * (2 + 12 * cos(beta)) * pow(sin(beta / 2.), 6);
            else if (n == 6)
                smallD = -6 * sqrt(22) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 7);
        } else if (m == 0) {
            if (n == -6)
                smallD = 2 * sqrt(231) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 6);
            else if (n == -5)
                smallD = 6 * sqrt(77) * pow(cos(beta / 2.), 5) * cos(beta) * pow(sin(beta / 2.), 5);
            else if (n == -4)
                smallD = sqrt(14) * pow(cos(beta / 2.), 4) *
                         (15 + 33 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -3)
                smallD = sqrt(4.2) * pow(cos(beta / 2.), 3) *
                         (20 + 75 * (-1 + cos(beta)) + (165 * pow(-1 + cos(beta), 2)) / 2. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -2)
                smallD = 2 * sqrt(0.4666666666666667) * pow(cos(beta / 2.), 2) *
                         (15 + 90 * (-1 + cos(beta)) + (675 * pow(-1 + cos(beta), 2)) / 4. +
                          (495 * pow(-1 + cos(beta), 3)) / 4. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD =
                    sqrt(1.1666666666666667) * cos(beta / 2.) *
                    (6 + 60 * (-1 + cos(beta)) + 180 * pow(-1 + cos(beta), 2) + 225 * pow(-1 + cos(beta), 3) +
                     (495 * pow(-1 + cos(beta), 4)) / 4. + (99 * pow(-1 + cos(beta), 5)) / 4.) *
                    sin(beta / 2.);
            else if (n == 0)
                smallD =
                    (-5 + 105 * pow(cos(beta), 2) - 315 * pow(cos(beta), 4) + 231 * pow(cos(beta), 6)) / 16.;
            else if (n == 1)
                smallD = -(sqrt(1.1666666666666667) * cos(beta / 2.) *
                           (6 + 60 * (-1 + cos(beta)) + 180 * pow(-1 + cos(beta), 2) +
                            225 * pow(-1 + cos(beta), 3) + (495 * pow(-1 + cos(beta), 4)) / 4. +
                            (99 * pow(-1 + cos(beta), 5)) / 4.) *
                           sin(beta / 2.));
            else if (n == 2)
                smallD = 2 * sqrt(0.4666666666666667) * pow(cos(beta / 2.), 2) *
                         (15 + 90 * (-1 + cos(beta)) + (675 * pow(-1 + cos(beta), 2)) / 4. +
                          (495 * pow(-1 + cos(beta), 3)) / 4. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = -(sqrt(4.2) * pow(cos(beta / 2.), 3) *
                           (20 + 75 * (-1 + cos(beta)) + (165 * pow(-1 + cos(beta), 2)) / 2. +
                            (55 * pow(-1 + cos(beta), 3)) / 2.) *
                           pow(sin(beta / 2.), 3));
            else if (n == 4)
                smallD = sqrt(14) * pow(cos(beta / 2.), 4) *
                         (15 + 33 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 5)
                smallD = -6 * sqrt(77) * pow(cos(beta / 2.), 5) * cos(beta) * pow(sin(beta / 2.), 5);
            else if (n == 6)
                smallD = 2 * sqrt(231) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 6);
        } else if (m == 1) {
            if (n == -6)
                smallD = 6 * sqrt(22) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 7);
            else if (n == -5)
                smallD = sqrt(16.5) * pow(cos(beta / 2.), 4) * (2 + 12 * cos(beta)) * pow(sin(beta / 2.), 6);
            else if (n == -4)
                smallD = 2 * sqrt(3) * pow(cos(beta / 2.), 3) *
                         (21 + (77 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -3)
                smallD = 3 * sqrt(0.4) * pow(cos(beta / 2.), 2) *
                         (35 + 105 * (-1 + cos(beta)) + (385 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -2)
                smallD = 2 * sqrt(0.4) * cos(beta / 2.) *
                         (35 + (315 * (-1 + cos(beta))) / 2. + (945 * pow(-1 + cos(beta), 2)) / 4. +
                          (1155 * pow(-1 + cos(beta), 3)) / 8. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -1)
                smallD = (21 + 140 * (-1 + cos(beta)) + 315 * pow(-1 + cos(beta), 2) +
                          315 * pow(-1 + cos(beta), 3) + (1155 * pow(-1 + cos(beta), 4)) / 8. +
                          (99 * pow(-1 + cos(beta), 5)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD =
                    sqrt(1.1666666666666667) * cos(beta / 2.) *
                    (6 + 60 * (-1 + cos(beta)) + 180 * pow(-1 + cos(beta), 2) + 225 * pow(-1 + cos(beta), 3) +
                     (495 * pow(-1 + cos(beta), 4)) / 4. + (99 * pow(-1 + cos(beta), 5)) / 4.) *
                    sin(beta / 2.);
            else if (n == 1)
                smallD =
                    pow(cos(beta / 2.), 2) *
                    (1 + 20 * (-1 + cos(beta)) + 90 * pow(-1 + cos(beta), 2) + 150 * pow(-1 + cos(beta), 3) +
                     (825 * pow(-1 + cos(beta), 4)) / 8. + (99 * pow(-1 + cos(beta), 5)) / 4.);
            else if (n == 2)
                smallD = -2 * sqrt(0.4) * pow(cos(beta / 2.), 3) *
                         (5 + 45 * (-1 + cos(beta)) + (225 * pow(-1 + cos(beta), 2)) / 2. +
                          (825 * pow(-1 + cos(beta), 3)) / 8. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         sin(beta / 2.);
            else if (n == 3)
                smallD = 3 * sqrt(0.4) * pow(cos(beta / 2.), 4) *
                         (10 + 50 * (-1 + cos(beta)) + (275 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 4)
                smallD = -2 * sqrt(3) * pow(cos(beta / 2.), 5) *
                         (10 + (55 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 5)
                smallD = sqrt(16.5) * pow(cos(beta / 2.), 6) * (-2 + 12 * cos(beta)) * pow(sin(beta / 2.), 4);
            else if (n == 6)
                smallD = -6 * sqrt(22) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 5);
        } else if (m == 2) {
            if (n == -6)
                smallD = 3 * sqrt(55) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 8);
            else if (n == -5)
                smallD =
                    (sqrt(165) * pow(cos(beta / 2.), 3) * (4 + 12 * cos(beta)) * pow(sin(beta / 2.), 7)) / 4.;
            else if (n == -4)
                smallD = sqrt(7.5) * pow(cos(beta / 2.), 2) *
                         (28 + 44 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -3)
                smallD = (3 * cos(beta / 2.) *
                          (56 + 140 * (-1 + cos(beta)) + 110 * pow(-1 + cos(beta), 2) +
                           (55 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == -2)
                smallD = (70 + 252 * (-1 + cos(beta)) + 315 * pow(-1 + cos(beta), 2) +
                          165 * pow(-1 + cos(beta), 3) + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -1)
                smallD = 2 * sqrt(0.4) * cos(beta / 2.) *
                         (35 + (315 * (-1 + cos(beta))) / 2. + (945 * pow(-1 + cos(beta), 2)) / 4. +
                          (1155 * pow(-1 + cos(beta), 3)) / 8. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 0)
                smallD = 2 * sqrt(0.4666666666666667) * pow(cos(beta / 2.), 2) *
                         (15 + 90 * (-1 + cos(beta)) + (675 * pow(-1 + cos(beta), 2)) / 4. +
                          (495 * pow(-1 + cos(beta), 3)) / 4. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = 2 * sqrt(0.4) * pow(cos(beta / 2.), 3) *
                         (5 + 45 * (-1 + cos(beta)) + (225 * pow(-1 + cos(beta), 2)) / 2. +
                          (825 * pow(-1 + cos(beta), 3)) / 8. + (495 * pow(-1 + cos(beta), 4)) / 16.) *
                         sin(beta / 2.);
            else if (n == 2)
                smallD = pow(cos(beta / 2.), 4) *
                         (1 + 18 * (-1 + cos(beta)) + (135 * pow(-1 + cos(beta), 2)) / 2. +
                          (165 * pow(-1 + cos(beta), 3)) / 2. + (495 * pow(-1 + cos(beta), 4)) / 16.);
            else if (n == 3)
                smallD = (-3 * pow(cos(beta / 2.), 5) *
                          (4 + 30 * (-1 + cos(beta)) + 55 * pow(-1 + cos(beta), 2) +
                           (55 * pow(-1 + cos(beta), 3)) / 2.) *
                          sin(beta / 2.)) /
                         2.;
            else if (n == 4)
                smallD = sqrt(7.5) * pow(cos(beta / 2.), 6) *
                         (6 + 22 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 5)
                smallD =
                    -(sqrt(165) * pow(cos(beta / 2.), 7) * (-4 + 12 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    4.;
            else if (n == 6)
                smallD = 3 * sqrt(55) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 4);
        } else if (m == 3) {
            if (n == -6)
                smallD = 2 * sqrt(55) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 9);
            else if (n == -5)
                smallD = (sqrt(18.333333333333332) * pow(cos(beta / 2.), 2) * (6 + 12 * cos(beta)) *
                          pow(sin(beta / 2.), 8)) /
                         2.;
            else if (n == -4)
                smallD = sqrt(3.3333333333333335) * cos(beta / 2.) *
                         (36 + (99 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 7);
            else if (n == -3)
                smallD = (84 + 180 * (-1 + cos(beta)) + (495 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -2)
                smallD = (3 * cos(beta / 2.) *
                          (56 + 140 * (-1 + cos(beta)) + 110 * pow(-1 + cos(beta), 2) +
                           (55 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == -1)
                smallD = 3 * sqrt(0.4) * pow(cos(beta / 2.), 2) *
                         (35 + 105 * (-1 + cos(beta)) + (385 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = sqrt(4.2) * pow(cos(beta / 2.), 3) *
                         (20 + 75 * (-1 + cos(beta)) + (165 * pow(-1 + cos(beta), 2)) / 2. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD = 3 * sqrt(0.4) * pow(cos(beta / 2.), 4) *
                         (10 + 50 * (-1 + cos(beta)) + (275 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = (3 * pow(cos(beta / 2.), 5) *
                          (4 + 30 * (-1 + cos(beta)) + 55 * pow(-1 + cos(beta), 2) +
                           (55 * pow(-1 + cos(beta), 3)) / 2.) *
                          sin(beta / 2.)) /
                         2.;
            else if (n == 3)
                smallD = pow(cos(beta / 2.), 6) *
                         (1 + 15 * (-1 + cos(beta)) + (165 * pow(-1 + cos(beta), 2)) / 4. +
                          (55 * pow(-1 + cos(beta), 3)) / 2.);
            else if (n == 4)
                smallD = -(sqrt(3.3333333333333335) * pow(cos(beta / 2.), 7) *
                           (3 + (33 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                           sin(beta / 2.));
            else if (n == 5)
                smallD = (sqrt(18.333333333333332) * pow(cos(beta / 2.), 8) * (-6 + 12 * cos(beta)) *
                          pow(sin(beta / 2.), 2)) /
                         2.;
            else if (n == 6)
                smallD = -2 * sqrt(55) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 3);
        } else if (m == 4) {
            if (n == -6)
                smallD = sqrt(66) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 10);
            else if (n == -5)
                smallD = (sqrt(5.5) * cos(beta / 2.) * (8 + 12 * cos(beta)) * pow(sin(beta / 2.), 9)) / 2.;
            else if (n == -4)
                smallD = (45 + 55 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 8);
            else if (n == -3)
                smallD = sqrt(3.3333333333333335) * cos(beta / 2.) *
                         (36 + (99 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 7);
            else if (n == -2)
                smallD = sqrt(7.5) * pow(cos(beta / 2.), 2) *
                         (28 + 44 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -1)
                smallD = 2 * sqrt(3) * pow(cos(beta / 2.), 3) *
                         (21 + (77 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 0)
                smallD = sqrt(14) * pow(cos(beta / 2.), 4) *
                         (15 + 33 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD = 2 * sqrt(3) * pow(cos(beta / 2.), 5) *
                         (10 + (55 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 2)
                smallD = sqrt(7.5) * pow(cos(beta / 2.), 6) *
                         (6 + 22 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = sqrt(3.3333333333333335) * pow(cos(beta / 2.), 7) *
                         (3 + (33 * (-1 + cos(beta))) / 2. + (33 * pow(-1 + cos(beta), 2)) / 2.) *
                         sin(beta / 2.);
            else if (n == 4)
                smallD =
                    pow(cos(beta / 2.), 8) * (1 + 11 * (-1 + cos(beta)) + (33 * pow(-1 + cos(beta), 2)) / 2.);
            else if (n == 5)
                smallD = -(sqrt(5.5) * pow(cos(beta / 2.), 9) * (-8 + 12 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 6)
                smallD = sqrt(66) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 2);
        } else if (m == 5) {
            if (n == -6)
                smallD = 2 * sqrt(3) * cos(beta / 2.) * pow(sin(beta / 2.), 11);
            else if (n == -5)
                smallD = ((10 + 12 * cos(beta)) * pow(sin(beta / 2.), 10)) / 2.;
            else if (n == -4)
                smallD = (sqrt(5.5) * cos(beta / 2.) * (8 + 12 * cos(beta)) * pow(sin(beta / 2.), 9)) / 2.;
            else if (n == -3)
                smallD = (sqrt(18.333333333333332) * pow(cos(beta / 2.), 2) * (6 + 12 * cos(beta)) *
                          pow(sin(beta / 2.), 8)) /
                         2.;
            else if (n == -2)
                smallD =
                    (sqrt(165) * pow(cos(beta / 2.), 3) * (4 + 12 * cos(beta)) * pow(sin(beta / 2.), 7)) / 4.;
            else if (n == -1)
                smallD = sqrt(16.5) * pow(cos(beta / 2.), 4) * (2 + 12 * cos(beta)) * pow(sin(beta / 2.), 6);
            else if (n == 0)
                smallD = 6 * sqrt(77) * pow(cos(beta / 2.), 5) * cos(beta) * pow(sin(beta / 2.), 5);
            else if (n == 1)
                smallD = sqrt(16.5) * pow(cos(beta / 2.), 6) * (-2 + 12 * cos(beta)) * pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD =
                    (sqrt(165) * pow(cos(beta / 2.), 7) * (-4 + 12 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    4.;
            else if (n == 3)
                smallD = (sqrt(18.333333333333332) * pow(cos(beta / 2.), 8) * (-6 + 12 * cos(beta)) *
                          pow(sin(beta / 2.), 2)) /
                         2.;
            else if (n == 4)
                smallD = (sqrt(5.5) * pow(cos(beta / 2.), 9) * (-8 + 12 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 5)
                smallD = (pow(cos(beta / 2.), 10) * (-10 + 12 * cos(beta))) / 2.;
            else if (n == 6)
                smallD = -2 * sqrt(3) * pow(cos(beta / 2.), 11) * sin(beta / 2.);
        } else if (m == 6) {
            if (n == -6)
                smallD = pow(sin(beta / 2.), 12);
            else if (n == -5)
                smallD = 2 * sqrt(3) * cos(beta / 2.) * pow(sin(beta / 2.), 11);
            else if (n == -4)
                smallD = sqrt(66) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 10);
            else if (n == -3)
                smallD = 2 * sqrt(55) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 9);
            else if (n == -2)
                smallD = 3 * sqrt(55) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 8);
            else if (n == -1)
                smallD = 6 * sqrt(22) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 7);
            else if (n == 0)
                smallD = 2 * sqrt(231) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 6);
            else if (n == 1)
                smallD = 6 * sqrt(22) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 5);
            else if (n == 2)
                smallD = 3 * sqrt(55) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 4);
            else if (n == 3)
                smallD = 2 * sqrt(55) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 3);
            else if (n == 4)
                smallD = sqrt(66) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 2);
            else if (n == 5)
                smallD = 2 * sqrt(3) * pow(cos(beta / 2.), 11) * sin(beta / 2.);
            else if (n == 6)
                smallD = pow(cos(beta / 2.), 12);
        }
    }
    // L=7
    else if (L == 7) {
        if (m == -7) {
            if (n == -7)
                smallD = pow(cos(beta / 2.), 14);
            else if (n == -6)
                smallD = -(sqrt(14) * pow(cos(beta / 2.), 13) * sin(beta / 2.));
            else if (n == -5)
                smallD = sqrt(91) * pow(cos(beta / 2.), 12) * pow(sin(beta / 2.), 2);
            else if (n == -4)
                smallD = -2 * sqrt(91) * pow(cos(beta / 2.), 11) * pow(sin(beta / 2.), 3);
            else if (n == -3)
                smallD = sqrt(1001) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 4);
            else if (n == -2)
                smallD = -(sqrt(2002) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 5));
            else if (n == -1)
                smallD = sqrt(3003) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 6);
            else if (n == 0)
                smallD = -2 * sqrt(858) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 7);
            else if (n == 1)
                smallD = sqrt(3003) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 8);
            else if (n == 2)
                smallD = -(sqrt(2002) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 9));
            else if (n == 3)
                smallD = sqrt(1001) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 10);
            else if (n == 4)
                smallD = -2 * sqrt(91) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 11);
            else if (n == 5)
                smallD = sqrt(91) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 12);
            else if (n == 6)
                smallD = -(sqrt(14) * cos(beta / 2.) * pow(sin(beta / 2.), 13));
            else if (n == 7)
                smallD = pow(sin(beta / 2.), 14);
        } else if (m == -6) {
            if (n == -7)
                smallD = sqrt(14) * pow(cos(beta / 2.), 13) * sin(beta / 2.);
            else if (n == -6)
                smallD = (pow(cos(beta / 2.), 12) * (-12 + 14 * cos(beta))) / 2.;
            else if (n == -5)
                smallD =
                    -(sqrt(6.5) * pow(cos(beta / 2.), 11) * (-10 + 14 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -4)
                smallD = sqrt(6.5) * pow(cos(beta / 2.), 10) * (-8 + 14 * cos(beta)) * pow(sin(beta / 2.), 2);
            else if (n == -3)
                smallD =
                    -(sqrt(71.5) * pow(cos(beta / 2.), 9) * (-6 + 14 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    2.;
            else if (n == -2)
                smallD =
                    (sqrt(143) * pow(cos(beta / 2.), 8) * (-4 + 14 * cos(beta)) * pow(sin(beta / 2.), 4)) /
                    2.;
            else if (n == -1)
                smallD =
                    -(sqrt(214.5) * pow(cos(beta / 2.), 7) * (-2 + 14 * cos(beta)) * pow(sin(beta / 2.), 5)) /
                    2.;
            else if (n == 0)
                smallD = 2 * sqrt(3003) * pow(cos(beta / 2.), 6) * cos(beta) * pow(sin(beta / 2.), 6);
            else if (n == 1)
                smallD =
                    -(sqrt(214.5) * pow(cos(beta / 2.), 5) * (2 + 14 * cos(beta)) * pow(sin(beta / 2.), 7)) /
                    2.;
            else if (n == 2)
                smallD =
                    (sqrt(143) * pow(cos(beta / 2.), 4) * (4 + 14 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == 3)
                smallD =
                    -(sqrt(71.5) * pow(cos(beta / 2.), 3) * (6 + 14 * cos(beta)) * pow(sin(beta / 2.), 9)) /
                    2.;
            else if (n == 4)
                smallD = sqrt(6.5) * pow(cos(beta / 2.), 2) * (8 + 14 * cos(beta)) * pow(sin(beta / 2.), 10);
            else if (n == 5)
                smallD = -(sqrt(6.5) * cos(beta / 2.) * (10 + 14 * cos(beta)) * pow(sin(beta / 2.), 11)) / 2.;
            else if (n == 6)
                smallD = ((12 + 14 * cos(beta)) * pow(sin(beta / 2.), 12)) / 2.;
            else if (n == 7)
                smallD = -(sqrt(14) * cos(beta / 2.) * pow(sin(beta / 2.), 13));
        } else if (m == -5) {
            if (n == -7)
                smallD = sqrt(91) * pow(cos(beta / 2.), 12) * pow(sin(beta / 2.), 2);
            else if (n == -6)
                smallD = (sqrt(6.5) * pow(cos(beta / 2.), 11) * (-10 + 14 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -5)
                smallD = pow(cos(beta / 2.), 10) *
                         (1 + 13 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.);
            else if (n == -4)
                smallD = -2 * pow(cos(beta / 2.), 9) *
                         (3 + (39 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         sin(beta / 2.);
            else if (n == -3)
                smallD = sqrt(11) * pow(cos(beta / 2.), 8) *
                         (6 + 26 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -2)
                smallD = -(sqrt(22) * pow(cos(beta / 2.), 7) *
                           (10 + (65 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                           pow(sin(beta / 2.), 3));
            else if (n == -1)
                smallD = sqrt(33) * pow(cos(beta / 2.), 6) *
                         (15 + 39 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = -2 * sqrt(9.428571428571429) * pow(cos(beta / 2.), 5) *
                         (21 + (91 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 1)
                smallD = sqrt(33) * pow(cos(beta / 2.), 4) *
                         (28 + 52 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 2)
                smallD = -(sqrt(22) * pow(cos(beta / 2.), 3) *
                           (36 + (117 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                           pow(sin(beta / 2.), 7));
            else if (n == 3)
                smallD = sqrt(11) * pow(cos(beta / 2.), 2) *
                         (45 + 65 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 8);
            else if (n == 4)
                smallD = -2 * cos(beta / 2.) *
                         (55 + (143 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 9);
            else if (n == 5)
                smallD = (66 + 78 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 10);
            else if (n == 6)
                smallD = -(sqrt(6.5) * cos(beta / 2.) * (10 + 14 * cos(beta)) * pow(sin(beta / 2.), 11)) / 2.;
            else if (n == 7)
                smallD = sqrt(91) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 12);
        } else if (m == -4) {
            if (n == -7)
                smallD = 2 * sqrt(91) * pow(cos(beta / 2.), 11) * pow(sin(beta / 2.), 3);
            else if (n == -6)
                smallD = sqrt(6.5) * pow(cos(beta / 2.), 10) * (-8 + 14 * cos(beta)) * pow(sin(beta / 2.), 2);
            else if (n == -5)
                smallD = 2 * pow(cos(beta / 2.), 9) *
                         (3 + (39 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         sin(beta / 2.);
            else if (n == -4)
                smallD = pow(cos(beta / 2.), 8) *
                         (1 + 18 * (-1 + cos(beta)) + (117 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.);
            else if (n == -3)
                smallD = -(sqrt(11) * pow(cos(beta / 2.), 7) *
                           (4 + 36 * (-1 + cos(beta)) + 78 * pow(-1 + cos(beta), 2) +
                            (91 * pow(-1 + cos(beta), 3)) / 2.) *
                           sin(beta / 2.)) /
                         2.;
            else if (n == -2)
                smallD = sqrt(5.5) * pow(cos(beta / 2.), 6) *
                         (10 + 60 * (-1 + cos(beta)) + (195 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD = -(sqrt(33) * pow(cos(beta / 2.), 5) *
                           (20 + 90 * (-1 + cos(beta)) + 117 * pow(-1 + cos(beta), 2) +
                            (91 * pow(-1 + cos(beta), 3)) / 2.) *
                           pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 0)
                smallD = sqrt(9.428571428571429) * pow(cos(beta / 2.), 4) *
                         (35 + 126 * (-1 + cos(beta)) + (273 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD = -(sqrt(33) * pow(cos(beta / 2.), 3) *
                           (56 + 168 * (-1 + cos(beta)) + 156 * pow(-1 + cos(beta), 2) +
                            (91 * pow(-1 + cos(beta), 3)) / 2.) *
                           pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == 2)
                smallD = sqrt(5.5) * pow(cos(beta / 2.), 2) *
                         (84 + 216 * (-1 + cos(beta)) + (351 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 3)
                smallD = -(sqrt(11) * cos(beta / 2.) *
                           (120 + 270 * (-1 + cos(beta)) + 195 * pow(-1 + cos(beta), 2) +
                            (91 * pow(-1 + cos(beta), 3)) / 2.) *
                           pow(sin(beta / 2.), 7)) /
                         2.;
            else if (n == 4)
                smallD = (165 + 330 * (-1 + cos(beta)) + (429 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 8);
            else if (n == 5)
                smallD = -2 * cos(beta / 2.) *
                         (55 + (143 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 9);
            else if (n == 6)
                smallD = sqrt(6.5) * pow(cos(beta / 2.), 2) * (8 + 14 * cos(beta)) * pow(sin(beta / 2.), 10);
            else if (n == 7)
                smallD = -2 * sqrt(91) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 11);
        } else if (m == -3) {
            if (n == -7)
                smallD = sqrt(1001) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 4);
            else if (n == -6)
                smallD =
                    (sqrt(71.5) * pow(cos(beta / 2.), 9) * (-6 + 14 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    2.;
            else if (n == -5)
                smallD = sqrt(11) * pow(cos(beta / 2.), 8) *
                         (6 + 26 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -4)
                smallD = (sqrt(11) * pow(cos(beta / 2.), 7) *
                          (4 + 36 * (-1 + cos(beta)) + 78 * pow(-1 + cos(beta), 2) +
                           (91 * pow(-1 + cos(beta), 3)) / 2.) *
                          sin(beta / 2.)) /
                         2.;
            else if (n == -3)
                smallD = pow(cos(beta / 2.), 6) *
                         (1 + 22 * (-1 + cos(beta)) + 99 * pow(-1 + cos(beta), 2) +
                          143 * pow(-1 + cos(beta), 3) + (1001 * pow(-1 + cos(beta), 4)) / 16.);
            else if (n == -2)
                smallD = -(sqrt(2) * pow(cos(beta / 2.), 5) *
                           (5 + 55 * (-1 + cos(beta)) + 165 * pow(-1 + cos(beta), 2) +
                            (715 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                           sin(beta / 2.));
            else if (n == -1)
                smallD = sqrt(3) * pow(cos(beta / 2.), 4) *
                         (15 + 110 * (-1 + cos(beta)) + (495 * pow(-1 + cos(beta), 2)) / 2. +
                          (429 * pow(-1 + cos(beta), 3)) / 2. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = -2 * sqrt(0.8571428571428571) * pow(cos(beta / 2.), 3) *
                         (35 + (385 * (-1 + cos(beta))) / 2. + (693 * pow(-1 + cos(beta), 2)) / 2. +
                          (1001 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD = sqrt(3) * pow(cos(beta / 2.), 2) *
                         (70 + 308 * (-1 + cos(beta)) + 462 * pow(-1 + cos(beta), 2) +
                          286 * pow(-1 + cos(beta), 3) + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD = -(sqrt(2) * cos(beta / 2.) *
                           (126 + 462 * (-1 + cos(beta)) + 594 * pow(-1 + cos(beta), 2) +
                            (1287 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                           pow(sin(beta / 2.), 5));
            else if (n == 3)
                smallD = (210 + 660 * (-1 + cos(beta)) + (1485 * pow(-1 + cos(beta), 2)) / 2. +
                          (715 * pow(-1 + cos(beta), 3)) / 2. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 4)
                smallD = -(sqrt(11) * cos(beta / 2.) *
                           (120 + 270 * (-1 + cos(beta)) + 195 * pow(-1 + cos(beta), 2) +
                            (91 * pow(-1 + cos(beta), 3)) / 2.) *
                           pow(sin(beta / 2.), 7)) /
                         2.;
            else if (n == 5)
                smallD = sqrt(11) * pow(cos(beta / 2.), 2) *
                         (45 + 65 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 8);
            else if (n == 6)
                smallD =
                    -(sqrt(71.5) * pow(cos(beta / 2.), 3) * (6 + 14 * cos(beta)) * pow(sin(beta / 2.), 9)) /
                    2.;
            else if (n == 7)
                smallD = sqrt(1001) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 10);
        } else if (m == -2) {
            if (n == -7)
                smallD = sqrt(2002) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 5);
            else if (n == -6)
                smallD =
                    (sqrt(143) * pow(cos(beta / 2.), 8) * (-4 + 14 * cos(beta)) * pow(sin(beta / 2.), 4)) /
                    2.;
            else if (n == -5)
                smallD = sqrt(22) * pow(cos(beta / 2.), 7) *
                         (10 + (65 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -4)
                smallD = sqrt(5.5) * pow(cos(beta / 2.), 6) *
                         (10 + 60 * (-1 + cos(beta)) + (195 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -3)
                smallD = sqrt(2) * pow(cos(beta / 2.), 5) *
                         (5 + 55 * (-1 + cos(beta)) + 165 * pow(-1 + cos(beta), 2) +
                          (715 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         sin(beta / 2.);
            else if (n == -2)
                smallD = pow(cos(beta / 2.), 4) *
                         (1 + 25 * (-1 + cos(beta)) + (275 * pow(-1 + cos(beta), 2)) / 2. +
                          275 * pow(-1 + cos(beta), 3) + (3575 * pow(-1 + cos(beta), 4)) / 16. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.);
            else if (n == -1)
                smallD = -(sqrt(1.5) * pow(cos(beta / 2.), 3) *
                           (6 + 75 * (-1 + cos(beta)) + 275 * pow(-1 + cos(beta), 2) +
                            (825 * pow(-1 + cos(beta), 3)) / 2. + (2145 * pow(-1 + cos(beta), 4)) / 8. +
                            (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                           sin(beta / 2.));
            else if (n == 0)
                smallD = 2 * sqrt(0.42857142857142855) * pow(cos(beta / 2.), 2) *
                         (21 + 175 * (-1 + cos(beta)) + (1925 * pow(-1 + cos(beta), 2)) / 4. +
                          (1155 * pow(-1 + cos(beta), 3)) / 2. + (5005 * pow(-1 + cos(beta), 4)) / 16. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = -(sqrt(1.5) * cos(beta / 2.) *
                           (56 + 350 * (-1 + cos(beta)) + 770 * pow(-1 + cos(beta), 2) +
                            770 * pow(-1 + cos(beta), 3) + (715 * pow(-1 + cos(beta), 4)) / 2. +
                            (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                           pow(sin(beta / 2.), 3));
            else if (n == 2)
                smallD = (126 + 630 * (-1 + cos(beta)) + 1155 * pow(-1 + cos(beta), 2) +
                          990 * pow(-1 + cos(beta), 3) + (6435 * pow(-1 + cos(beta), 4)) / 16. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 3)
                smallD = -(sqrt(2) * cos(beta / 2.) *
                           (126 + 462 * (-1 + cos(beta)) + 594 * pow(-1 + cos(beta), 2) +
                            (1287 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                           pow(sin(beta / 2.), 5));
            else if (n == 4)
                smallD = sqrt(5.5) * pow(cos(beta / 2.), 2) *
                         (84 + 216 * (-1 + cos(beta)) + (351 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 5)
                smallD = -(sqrt(22) * pow(cos(beta / 2.), 3) *
                           (36 + (117 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                           pow(sin(beta / 2.), 7));
            else if (n == 6)
                smallD =
                    (sqrt(143) * pow(cos(beta / 2.), 4) * (4 + 14 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == 7)
                smallD = -(sqrt(2002) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 9));
        } else if (m == -1) {
            if (n == -7)
                smallD = sqrt(3003) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 6);
            else if (n == -6)
                smallD =
                    (sqrt(214.5) * pow(cos(beta / 2.), 7) * (-2 + 14 * cos(beta)) * pow(sin(beta / 2.), 5)) /
                    2.;
            else if (n == -5)
                smallD = sqrt(33) * pow(cos(beta / 2.), 6) *
                         (15 + 39 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -4)
                smallD = (sqrt(33) * pow(cos(beta / 2.), 5) *
                          (20 + 90 * (-1 + cos(beta)) + 117 * pow(-1 + cos(beta), 2) +
                           (91 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == -3)
                smallD = sqrt(3) * pow(cos(beta / 2.), 4) *
                         (15 + 110 * (-1 + cos(beta)) + (495 * pow(-1 + cos(beta), 2)) / 2. +
                          (429 * pow(-1 + cos(beta), 3)) / 2. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -2)
                smallD = sqrt(1.5) * pow(cos(beta / 2.), 3) *
                         (6 + 75 * (-1 + cos(beta)) + 275 * pow(-1 + cos(beta), 2) +
                          (825 * pow(-1 + cos(beta), 3)) / 2. + (2145 * pow(-1 + cos(beta), 4)) / 8. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         sin(beta / 2.);
            else if (n == -1)
                smallD = pow(cos(beta / 2.), 2) *
                         (1 + 27 * (-1 + cos(beta)) + (675 * pow(-1 + cos(beta), 2)) / 4. +
                          (825 * pow(-1 + cos(beta), 3)) / 2. + (7425 * pow(-1 + cos(beta), 4)) / 16. +
                          (3861 * pow(-1 + cos(beta), 5)) / 16. + (3003 * pow(-1 + cos(beta), 6)) / 64.);
            else if (n == 0)
                smallD = -2 * sqrt(0.2857142857142857) * cos(beta / 2.) *
                         (7 + (189 * (-1 + cos(beta))) / 2. + (1575 * pow(-1 + cos(beta), 2)) / 4. +
                          (5775 * pow(-1 + cos(beta), 3)) / 8. + (10395 * pow(-1 + cos(beta), 4)) / 16. +
                          (9009 * pow(-1 + cos(beta), 5)) / 32. + (3003 * pow(-1 + cos(beta), 6)) / 64.) *
                         sin(beta / 2.);
            else if (n == 1)
                smallD = (28 + 252 * (-1 + cos(beta)) + (1575 * pow(-1 + cos(beta), 2)) / 2. +
                          1155 * pow(-1 + cos(beta), 3) + (3465 * pow(-1 + cos(beta), 4)) / 4. +
                          (1287 * pow(-1 + cos(beta), 5)) / 4. + (3003 * pow(-1 + cos(beta), 6)) / 64.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = -(sqrt(1.5) * cos(beta / 2.) *
                           (56 + 350 * (-1 + cos(beta)) + 770 * pow(-1 + cos(beta), 2) +
                            770 * pow(-1 + cos(beta), 3) + (715 * pow(-1 + cos(beta), 4)) / 2. +
                            (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                           pow(sin(beta / 2.), 3));
            else if (n == 3)
                smallD = sqrt(3) * pow(cos(beta / 2.), 2) *
                         (70 + 308 * (-1 + cos(beta)) + 462 * pow(-1 + cos(beta), 2) +
                          286 * pow(-1 + cos(beta), 3) + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 4)
                smallD = -(sqrt(33) * pow(cos(beta / 2.), 3) *
                           (56 + 168 * (-1 + cos(beta)) + 156 * pow(-1 + cos(beta), 2) +
                            (91 * pow(-1 + cos(beta), 3)) / 2.) *
                           pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == 5)
                smallD = sqrt(33) * pow(cos(beta / 2.), 4) *
                         (28 + 52 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 6)
                smallD =
                    -(sqrt(214.5) * pow(cos(beta / 2.), 5) * (2 + 14 * cos(beta)) * pow(sin(beta / 2.), 7)) /
                    2.;
            else if (n == 7)
                smallD = sqrt(3003) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 8);
        } else if (m == 0) {
            if (n == -7)
                smallD = 2 * sqrt(858) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 7);
            else if (n == -6)
                smallD = 2 * sqrt(3003) * pow(cos(beta / 2.), 6) * cos(beta) * pow(sin(beta / 2.), 6);
            else if (n == -5)
                smallD = 2 * sqrt(9.428571428571429) * pow(cos(beta / 2.), 5) *
                         (21 + (91 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -4)
                smallD = sqrt(9.428571428571429) * pow(cos(beta / 2.), 4) *
                         (35 + 126 * (-1 + cos(beta)) + (273 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -3)
                smallD = 2 * sqrt(0.8571428571428571) * pow(cos(beta / 2.), 3) *
                         (35 + (385 * (-1 + cos(beta))) / 2. + (693 * pow(-1 + cos(beta), 2)) / 2. +
                          (1001 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -2)
                smallD = 2 * sqrt(0.42857142857142855) * pow(cos(beta / 2.), 2) *
                         (21 + 175 * (-1 + cos(beta)) + (1925 * pow(-1 + cos(beta), 2)) / 4. +
                          (1155 * pow(-1 + cos(beta), 3)) / 2. + (5005 * pow(-1 + cos(beta), 4)) / 16. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD = 2 * sqrt(0.2857142857142857) * cos(beta / 2.) *
                         (7 + (189 * (-1 + cos(beta))) / 2. + (1575 * pow(-1 + cos(beta), 2)) / 4. +
                          (5775 * pow(-1 + cos(beta), 3)) / 8. + (10395 * pow(-1 + cos(beta), 4)) / 16. +
                          (9009 * pow(-1 + cos(beta), 5)) / 32. + (3003 * pow(-1 + cos(beta), 6)) / 64.) *
                         sin(beta / 2.);
            else if (n == 0)
                smallD = (-35 * cos(beta) + 315 * pow(cos(beta), 3) - 693 * pow(cos(beta), 5) +
                          429 * pow(cos(beta), 7)) /
                         16.;
            else if (n == 1)
                smallD = -2 * sqrt(0.2857142857142857) * cos(beta / 2.) *
                         (7 + (189 * (-1 + cos(beta))) / 2. + (1575 * pow(-1 + cos(beta), 2)) / 4. +
                          (5775 * pow(-1 + cos(beta), 3)) / 8. + (10395 * pow(-1 + cos(beta), 4)) / 16. +
                          (9009 * pow(-1 + cos(beta), 5)) / 32. + (3003 * pow(-1 + cos(beta), 6)) / 64.) *
                         sin(beta / 2.);
            else if (n == 2)
                smallD = 2 * sqrt(0.42857142857142855) * pow(cos(beta / 2.), 2) *
                         (21 + 175 * (-1 + cos(beta)) + (1925 * pow(-1 + cos(beta), 2)) / 4. +
                          (1155 * pow(-1 + cos(beta), 3)) / 2. + (5005 * pow(-1 + cos(beta), 4)) / 16. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = -2 * sqrt(0.8571428571428571) * pow(cos(beta / 2.), 3) *
                         (35 + (385 * (-1 + cos(beta))) / 2. + (693 * pow(-1 + cos(beta), 2)) / 2. +
                          (1001 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 4)
                smallD = sqrt(9.428571428571429) * pow(cos(beta / 2.), 4) *
                         (35 + 126 * (-1 + cos(beta)) + (273 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 5)
                smallD = -2 * sqrt(9.428571428571429) * pow(cos(beta / 2.), 5) *
                         (21 + (91 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 6)
                smallD = 2 * sqrt(3003) * pow(cos(beta / 2.), 6) * cos(beta) * pow(sin(beta / 2.), 6);
            else if (n == 7)
                smallD = -2 * sqrt(858) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 7);
        } else if (m == 1) {
            if (n == -7)
                smallD = sqrt(3003) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 8);
            else if (n == -6)
                smallD =
                    (sqrt(214.5) * pow(cos(beta / 2.), 5) * (2 + 14 * cos(beta)) * pow(sin(beta / 2.), 7)) /
                    2.;
            else if (n == -5)
                smallD = sqrt(33) * pow(cos(beta / 2.), 4) *
                         (28 + 52 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -4)
                smallD = (sqrt(33) * pow(cos(beta / 2.), 3) *
                          (56 + 168 * (-1 + cos(beta)) + 156 * pow(-1 + cos(beta), 2) +
                           (91 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == -3)
                smallD = sqrt(3) * pow(cos(beta / 2.), 2) *
                         (70 + 308 * (-1 + cos(beta)) + 462 * pow(-1 + cos(beta), 2) +
                          286 * pow(-1 + cos(beta), 3) + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -2)
                smallD = sqrt(1.5) * cos(beta / 2.) *
                         (56 + 350 * (-1 + cos(beta)) + 770 * pow(-1 + cos(beta), 2) +
                          770 * pow(-1 + cos(beta), 3) + (715 * pow(-1 + cos(beta), 4)) / 2. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -1)
                smallD = (28 + 252 * (-1 + cos(beta)) + (1575 * pow(-1 + cos(beta), 2)) / 2. +
                          1155 * pow(-1 + cos(beta), 3) + (3465 * pow(-1 + cos(beta), 4)) / 4. +
                          (1287 * pow(-1 + cos(beta), 5)) / 4. + (3003 * pow(-1 + cos(beta), 6)) / 64.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = 2 * sqrt(0.2857142857142857) * cos(beta / 2.) *
                         (7 + (189 * (-1 + cos(beta))) / 2. + (1575 * pow(-1 + cos(beta), 2)) / 4. +
                          (5775 * pow(-1 + cos(beta), 3)) / 8. + (10395 * pow(-1 + cos(beta), 4)) / 16. +
                          (9009 * pow(-1 + cos(beta), 5)) / 32. + (3003 * pow(-1 + cos(beta), 6)) / 64.) *
                         sin(beta / 2.);
            else if (n == 1)
                smallD = pow(cos(beta / 2.), 2) *
                         (1 + 27 * (-1 + cos(beta)) + (675 * pow(-1 + cos(beta), 2)) / 4. +
                          (825 * pow(-1 + cos(beta), 3)) / 2. + (7425 * pow(-1 + cos(beta), 4)) / 16. +
                          (3861 * pow(-1 + cos(beta), 5)) / 16. + (3003 * pow(-1 + cos(beta), 6)) / 64.);
            else if (n == 2)
                smallD = -(sqrt(1.5) * pow(cos(beta / 2.), 3) *
                           (6 + 75 * (-1 + cos(beta)) + 275 * pow(-1 + cos(beta), 2) +
                            (825 * pow(-1 + cos(beta), 3)) / 2. + (2145 * pow(-1 + cos(beta), 4)) / 8. +
                            (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                           sin(beta / 2.));
            else if (n == 3)
                smallD = sqrt(3) * pow(cos(beta / 2.), 4) *
                         (15 + 110 * (-1 + cos(beta)) + (495 * pow(-1 + cos(beta), 2)) / 2. +
                          (429 * pow(-1 + cos(beta), 3)) / 2. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 4)
                smallD = -(sqrt(33) * pow(cos(beta / 2.), 5) *
                           (20 + 90 * (-1 + cos(beta)) + 117 * pow(-1 + cos(beta), 2) +
                            (91 * pow(-1 + cos(beta), 3)) / 2.) *
                           pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 5)
                smallD = sqrt(33) * pow(cos(beta / 2.), 6) *
                         (15 + 39 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 6)
                smallD =
                    -(sqrt(214.5) * pow(cos(beta / 2.), 7) * (-2 + 14 * cos(beta)) * pow(sin(beta / 2.), 5)) /
                    2.;
            else if (n == 7)
                smallD = sqrt(3003) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 6);
        } else if (m == 2) {
            if (n == -7)
                smallD = sqrt(2002) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 9);
            else if (n == -6)
                smallD =
                    (sqrt(143) * pow(cos(beta / 2.), 4) * (4 + 14 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == -5)
                smallD = sqrt(22) * pow(cos(beta / 2.), 3) *
                         (36 + (117 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 7);
            else if (n == -4)
                smallD = sqrt(5.5) * pow(cos(beta / 2.), 2) *
                         (84 + 216 * (-1 + cos(beta)) + (351 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -3)
                smallD = sqrt(2) * cos(beta / 2.) *
                         (126 + 462 * (-1 + cos(beta)) + 594 * pow(-1 + cos(beta), 2) +
                          (1287 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -2)
                smallD = (126 + 630 * (-1 + cos(beta)) + 1155 * pow(-1 + cos(beta), 2) +
                          990 * pow(-1 + cos(beta), 3) + (6435 * pow(-1 + cos(beta), 4)) / 16. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -1)
                smallD = sqrt(1.5) * cos(beta / 2.) *
                         (56 + 350 * (-1 + cos(beta)) + 770 * pow(-1 + cos(beta), 2) +
                          770 * pow(-1 + cos(beta), 3) + (715 * pow(-1 + cos(beta), 4)) / 2. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 0)
                smallD = 2 * sqrt(0.42857142857142855) * pow(cos(beta / 2.), 2) *
                         (21 + 175 * (-1 + cos(beta)) + (1925 * pow(-1 + cos(beta), 2)) / 4. +
                          (1155 * pow(-1 + cos(beta), 3)) / 2. + (5005 * pow(-1 + cos(beta), 4)) / 16. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 1)
                smallD = sqrt(1.5) * pow(cos(beta / 2.), 3) *
                         (6 + 75 * (-1 + cos(beta)) + 275 * pow(-1 + cos(beta), 2) +
                          (825 * pow(-1 + cos(beta), 3)) / 2. + (2145 * pow(-1 + cos(beta), 4)) / 8. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.) *
                         sin(beta / 2.);
            else if (n == 2)
                smallD = pow(cos(beta / 2.), 4) *
                         (1 + 25 * (-1 + cos(beta)) + (275 * pow(-1 + cos(beta), 2)) / 2. +
                          275 * pow(-1 + cos(beta), 3) + (3575 * pow(-1 + cos(beta), 4)) / 16. +
                          (1001 * pow(-1 + cos(beta), 5)) / 16.);
            else if (n == 3)
                smallD = -(sqrt(2) * pow(cos(beta / 2.), 5) *
                           (5 + 55 * (-1 + cos(beta)) + 165 * pow(-1 + cos(beta), 2) +
                            (715 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                           sin(beta / 2.));
            else if (n == 4)
                smallD = sqrt(5.5) * pow(cos(beta / 2.), 6) *
                         (10 + 60 * (-1 + cos(beta)) + (195 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 5)
                smallD = -(sqrt(22) * pow(cos(beta / 2.), 7) *
                           (10 + (65 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                           pow(sin(beta / 2.), 3));
            else if (n == 6)
                smallD =
                    (sqrt(143) * pow(cos(beta / 2.), 8) * (-4 + 14 * cos(beta)) * pow(sin(beta / 2.), 4)) /
                    2.;
            else if (n == 7)
                smallD = -(sqrt(2002) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 5));
        } else if (m == 3) {
            if (n == -7)
                smallD = sqrt(1001) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 10);
            else if (n == -6)
                smallD =
                    (sqrt(71.5) * pow(cos(beta / 2.), 3) * (6 + 14 * cos(beta)) * pow(sin(beta / 2.), 9)) /
                    2.;
            else if (n == -5)
                smallD = sqrt(11) * pow(cos(beta / 2.), 2) *
                         (45 + 65 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 8);
            else if (n == -4)
                smallD = (sqrt(11) * cos(beta / 2.) *
                          (120 + 270 * (-1 + cos(beta)) + 195 * pow(-1 + cos(beta), 2) +
                           (91 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 7)) /
                         2.;
            else if (n == -3)
                smallD = (210 + 660 * (-1 + cos(beta)) + (1485 * pow(-1 + cos(beta), 2)) / 2. +
                          (715 * pow(-1 + cos(beta), 3)) / 2. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -2)
                smallD = sqrt(2) * cos(beta / 2.) *
                         (126 + 462 * (-1 + cos(beta)) + 594 * pow(-1 + cos(beta), 2) +
                          (1287 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -1)
                smallD = sqrt(3) * pow(cos(beta / 2.), 2) *
                         (70 + 308 * (-1 + cos(beta)) + 462 * pow(-1 + cos(beta), 2) +
                          286 * pow(-1 + cos(beta), 3) + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = 2 * sqrt(0.8571428571428571) * pow(cos(beta / 2.), 3) *
                         (35 + (385 * (-1 + cos(beta))) / 2. + (693 * pow(-1 + cos(beta), 2)) / 2. +
                          (1001 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 1)
                smallD = sqrt(3) * pow(cos(beta / 2.), 4) *
                         (15 + 110 * (-1 + cos(beta)) + (495 * pow(-1 + cos(beta), 2)) / 2. +
                          (429 * pow(-1 + cos(beta), 3)) / 2. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = sqrt(2) * pow(cos(beta / 2.), 5) *
                         (5 + 55 * (-1 + cos(beta)) + 165 * pow(-1 + cos(beta), 2) +
                          (715 * pow(-1 + cos(beta), 3)) / 4. + (1001 * pow(-1 + cos(beta), 4)) / 16.) *
                         sin(beta / 2.);
            else if (n == 3)
                smallD = pow(cos(beta / 2.), 6) *
                         (1 + 22 * (-1 + cos(beta)) + 99 * pow(-1 + cos(beta), 2) +
                          143 * pow(-1 + cos(beta), 3) + (1001 * pow(-1 + cos(beta), 4)) / 16.);
            else if (n == 4)
                smallD = -(sqrt(11) * pow(cos(beta / 2.), 7) *
                           (4 + 36 * (-1 + cos(beta)) + 78 * pow(-1 + cos(beta), 2) +
                            (91 * pow(-1 + cos(beta), 3)) / 2.) *
                           sin(beta / 2.)) /
                         2.;
            else if (n == 5)
                smallD = sqrt(11) * pow(cos(beta / 2.), 8) *
                         (6 + 26 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 6)
                smallD =
                    -(sqrt(71.5) * pow(cos(beta / 2.), 9) * (-6 + 14 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    2.;
            else if (n == 7)
                smallD = sqrt(1001) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 4);
        } else if (m == 4) {
            if (n == -7)
                smallD = 2 * sqrt(91) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 11);
            else if (n == -6)
                smallD = sqrt(6.5) * pow(cos(beta / 2.), 2) * (8 + 14 * cos(beta)) * pow(sin(beta / 2.), 10);
            else if (n == -5)
                smallD = 2 * cos(beta / 2.) *
                         (55 + (143 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 9);
            else if (n == -4)
                smallD = (165 + 330 * (-1 + cos(beta)) + (429 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 8);
            else if (n == -3)
                smallD = (sqrt(11) * cos(beta / 2.) *
                          (120 + 270 * (-1 + cos(beta)) + 195 * pow(-1 + cos(beta), 2) +
                           (91 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 7)) /
                         2.;
            else if (n == -2)
                smallD = sqrt(5.5) * pow(cos(beta / 2.), 2) *
                         (84 + 216 * (-1 + cos(beta)) + (351 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -1)
                smallD = (sqrt(33) * pow(cos(beta / 2.), 3) *
                          (56 + 168 * (-1 + cos(beta)) + 156 * pow(-1 + cos(beta), 2) +
                           (91 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == 0)
                smallD = sqrt(9.428571428571429) * pow(cos(beta / 2.), 4) *
                         (35 + 126 * (-1 + cos(beta)) + (273 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD = (sqrt(33) * pow(cos(beta / 2.), 5) *
                          (20 + 90 * (-1 + cos(beta)) + 117 * pow(-1 + cos(beta), 2) +
                           (91 * pow(-1 + cos(beta), 3)) / 2.) *
                          pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 2)
                smallD = sqrt(5.5) * pow(cos(beta / 2.), 6) *
                         (10 + 60 * (-1 + cos(beta)) + (195 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = (sqrt(11) * pow(cos(beta / 2.), 7) *
                          (4 + 36 * (-1 + cos(beta)) + 78 * pow(-1 + cos(beta), 2) +
                           (91 * pow(-1 + cos(beta), 3)) / 2.) *
                          sin(beta / 2.)) /
                         2.;
            else if (n == 4)
                smallD = pow(cos(beta / 2.), 8) *
                         (1 + 18 * (-1 + cos(beta)) + (117 * pow(-1 + cos(beta), 2)) / 2. +
                          (91 * pow(-1 + cos(beta), 3)) / 2.);
            else if (n == 5)
                smallD = -2 * pow(cos(beta / 2.), 9) *
                         (3 + (39 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         sin(beta / 2.);
            else if (n == 6)
                smallD = sqrt(6.5) * pow(cos(beta / 2.), 10) * (-8 + 14 * cos(beta)) * pow(sin(beta / 2.), 2);
            else if (n == 7)
                smallD = -2 * sqrt(91) * pow(cos(beta / 2.), 11) * pow(sin(beta / 2.), 3);
        } else if (m == 5) {
            if (n == -7)
                smallD = sqrt(91) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 12);
            else if (n == -6)
                smallD = (sqrt(6.5) * cos(beta / 2.) * (10 + 14 * cos(beta)) * pow(sin(beta / 2.), 11)) / 2.;
            else if (n == -5)
                smallD = (66 + 78 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 10);
            else if (n == -4)
                smallD = 2 * cos(beta / 2.) *
                         (55 + (143 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 9);
            else if (n == -3)
                smallD = sqrt(11) * pow(cos(beta / 2.), 2) *
                         (45 + 65 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 8);
            else if (n == -2)
                smallD = sqrt(22) * pow(cos(beta / 2.), 3) *
                         (36 + (117 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 7);
            else if (n == -1)
                smallD = sqrt(33) * pow(cos(beta / 2.), 4) *
                         (28 + 52 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 0)
                smallD = 2 * sqrt(9.428571428571429) * pow(cos(beta / 2.), 5) *
                         (21 + (91 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 1)
                smallD = sqrt(33) * pow(cos(beta / 2.), 6) *
                         (15 + 39 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD = sqrt(22) * pow(cos(beta / 2.), 7) *
                         (10 + (65 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 3)
                smallD = sqrt(11) * pow(cos(beta / 2.), 8) *
                         (6 + 26 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 4)
                smallD = 2 * pow(cos(beta / 2.), 9) *
                         (3 + (39 * (-1 + cos(beta))) / 2. + (91 * pow(-1 + cos(beta), 2)) / 4.) *
                         sin(beta / 2.);
            else if (n == 5)
                smallD = pow(cos(beta / 2.), 10) *
                         (1 + 13 * (-1 + cos(beta)) + (91 * pow(-1 + cos(beta), 2)) / 4.);
            else if (n == 6)
                smallD =
                    -(sqrt(6.5) * pow(cos(beta / 2.), 11) * (-10 + 14 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 7)
                smallD = sqrt(91) * pow(cos(beta / 2.), 12) * pow(sin(beta / 2.), 2);
        } else if (m == 6) {
            if (n == -7)
                smallD = sqrt(14) * cos(beta / 2.) * pow(sin(beta / 2.), 13);
            else if (n == -6)
                smallD = ((12 + 14 * cos(beta)) * pow(sin(beta / 2.), 12)) / 2.;
            else if (n == -5)
                smallD = (sqrt(6.5) * cos(beta / 2.) * (10 + 14 * cos(beta)) * pow(sin(beta / 2.), 11)) / 2.;
            else if (n == -4)
                smallD = sqrt(6.5) * pow(cos(beta / 2.), 2) * (8 + 14 * cos(beta)) * pow(sin(beta / 2.), 10);
            else if (n == -3)
                smallD =
                    (sqrt(71.5) * pow(cos(beta / 2.), 3) * (6 + 14 * cos(beta)) * pow(sin(beta / 2.), 9)) /
                    2.;
            else if (n == -2)
                smallD =
                    (sqrt(143) * pow(cos(beta / 2.), 4) * (4 + 14 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == -1)
                smallD =
                    (sqrt(214.5) * pow(cos(beta / 2.), 5) * (2 + 14 * cos(beta)) * pow(sin(beta / 2.), 7)) /
                    2.;
            else if (n == 0)
                smallD = 2 * sqrt(3003) * pow(cos(beta / 2.), 6) * cos(beta) * pow(sin(beta / 2.), 6);
            else if (n == 1)
                smallD =
                    (sqrt(214.5) * pow(cos(beta / 2.), 7) * (-2 + 14 * cos(beta)) * pow(sin(beta / 2.), 5)) /
                    2.;
            else if (n == 2)
                smallD =
                    (sqrt(143) * pow(cos(beta / 2.), 8) * (-4 + 14 * cos(beta)) * pow(sin(beta / 2.), 4)) /
                    2.;
            else if (n == 3)
                smallD =
                    (sqrt(71.5) * pow(cos(beta / 2.), 9) * (-6 + 14 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    2.;
            else if (n == 4)
                smallD = sqrt(6.5) * pow(cos(beta / 2.), 10) * (-8 + 14 * cos(beta)) * pow(sin(beta / 2.), 2);
            else if (n == 5)
                smallD = (sqrt(6.5) * pow(cos(beta / 2.), 11) * (-10 + 14 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 6)
                smallD = (pow(cos(beta / 2.), 12) * (-12 + 14 * cos(beta))) / 2.;
            else if (n == 7)
                smallD = -(sqrt(14) * pow(cos(beta / 2.), 13) * sin(beta / 2.));
        } else if (m == 7) {
            if (n == -7)
                smallD = pow(sin(beta / 2.), 14);
            else if (n == -6)
                smallD = sqrt(14) * cos(beta / 2.) * pow(sin(beta / 2.), 13);
            else if (n == -5)
                smallD = sqrt(91) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 12);
            else if (n == -4)
                smallD = 2 * sqrt(91) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 11);
            else if (n == -3)
                smallD = sqrt(1001) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 10);
            else if (n == -2)
                smallD = sqrt(2002) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 9);
            else if (n == -1)
                smallD = sqrt(3003) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 8);
            else if (n == 0)
                smallD = 2 * sqrt(858) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 7);
            else if (n == 1)
                smallD = sqrt(3003) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 6);
            else if (n == 2)
                smallD = sqrt(2002) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 5);
            else if (n == 3)
                smallD = sqrt(1001) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 4);
            else if (n == 4)
                smallD = 2 * sqrt(91) * pow(cos(beta / 2.), 11) * pow(sin(beta / 2.), 3);
            else if (n == 5)
                smallD = sqrt(91) * pow(cos(beta / 2.), 12) * pow(sin(beta / 2.), 2);
            else if (n == 6)
                smallD = sqrt(14) * pow(cos(beta / 2.), 13) * sin(beta / 2.);
            else if (n == 7)
                smallD = pow(cos(beta / 2.), 14);
        }
    }
    // L = 8
    else if (L == 8) {
        if (m == -8) {
            if (n == -8)
                smallD = pow(cos(beta / 2.), 16);
            else if (n == -7)
                smallD = -4 * pow(cos(beta / 2.), 15) * sin(beta / 2.);
            else if (n == -6)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 14) * pow(sin(beta / 2.), 2);
            else if (n == -5)
                smallD = -4 * sqrt(35) * pow(cos(beta / 2.), 13) * pow(sin(beta / 2.), 3);
            else if (n == -4)
                smallD = 2 * sqrt(455) * pow(cos(beta / 2.), 12) * pow(sin(beta / 2.), 4);
            else if (n == -3)
                smallD = -4 * sqrt(273) * pow(cos(beta / 2.), 11) * pow(sin(beta / 2.), 5);
            else if (n == -2)
                smallD = 2 * sqrt(2002) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 6);
            else if (n == -1)
                smallD = -4 * sqrt(715) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 7);
            else if (n == 0)
                smallD = 3 * sqrt(1430) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 8);
            else if (n == 1)
                smallD = -4 * sqrt(715) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 9);
            else if (n == 2)
                smallD = 2 * sqrt(2002) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 10);
            else if (n == 3)
                smallD = -4 * sqrt(273) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 11);
            else if (n == 4)
                smallD = 2 * sqrt(455) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 12);
            else if (n == 5)
                smallD = -4 * sqrt(35) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 13);
            else if (n == 6)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 14);
            else if (n == 7)
                smallD = -4 * cos(beta / 2.) * pow(sin(beta / 2.), 15);
            else if (n == 8)
                smallD = pow(sin(beta / 2.), 16);
        } else if (m == -7) {
            if (n == -8)
                smallD = 4 * pow(cos(beta / 2.), 15) * sin(beta / 2.);
            else if (n == -7)
                smallD = (pow(cos(beta / 2.), 14) * (-14 + 16 * cos(beta))) / 2.;
            else if (n == -6)
                smallD =
                    -(sqrt(7.5) * pow(cos(beta / 2.), 13) * (-12 + 16 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -5)
                smallD =
                    (sqrt(35) * pow(cos(beta / 2.), 12) * (-10 + 16 * cos(beta)) * pow(sin(beta / 2.), 2)) /
                    2.;
            else if (n == -4)
                smallD =
                    -(sqrt(455) * pow(cos(beta / 2.), 11) * (-8 + 16 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    4.;
            else if (n == -3)
                smallD =
                    (sqrt(273) * pow(cos(beta / 2.), 10) * (-6 + 16 * cos(beta)) * pow(sin(beta / 2.), 4)) /
                    2.;
            else if (n == -2)
                smallD =
                    -(sqrt(500.5) * pow(cos(beta / 2.), 9) * (-4 + 16 * cos(beta)) * pow(sin(beta / 2.), 5)) /
                    2.;
            else if (n == -1)
                smallD =
                    (sqrt(715) * pow(cos(beta / 2.), 8) * (-2 + 16 * cos(beta)) * pow(sin(beta / 2.), 6)) /
                    2.;
            else if (n == 0)
                smallD = -6 * sqrt(1430) * pow(cos(beta / 2.), 7) * cos(beta) * pow(sin(beta / 2.), 7);
            else if (n == 1)
                smallD =
                    (sqrt(715) * pow(cos(beta / 2.), 6) * (2 + 16 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == 2)
                smallD =
                    -(sqrt(500.5) * pow(cos(beta / 2.), 5) * (4 + 16 * cos(beta)) * pow(sin(beta / 2.), 9)) /
                    2.;
            else if (n == 3)
                smallD =
                    (sqrt(273) * pow(cos(beta / 2.), 4) * (6 + 16 * cos(beta)) * pow(sin(beta / 2.), 10)) /
                    2.;
            else if (n == 4)
                smallD =
                    -(sqrt(455) * pow(cos(beta / 2.), 3) * (8 + 16 * cos(beta)) * pow(sin(beta / 2.), 11)) /
                    4.;
            else if (n == 5)
                smallD =
                    (sqrt(35) * pow(cos(beta / 2.), 2) * (10 + 16 * cos(beta)) * pow(sin(beta / 2.), 12)) /
                    2.;
            else if (n == 6)
                smallD = -(sqrt(7.5) * cos(beta / 2.) * (12 + 16 * cos(beta)) * pow(sin(beta / 2.), 13)) / 2.;
            else if (n == 7)
                smallD = ((14 + 16 * cos(beta)) * pow(sin(beta / 2.), 14)) / 2.;
            else if (n == 8)
                smallD = -4 * cos(beta / 2.) * pow(sin(beta / 2.), 15);
        } else if (m == -6) {
            if (n == -8)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 14) * pow(sin(beta / 2.), 2);
            else if (n == -7)
                smallD = (sqrt(7.5) * pow(cos(beta / 2.), 13) * (-12 + 16 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == -6)
                smallD = pow(cos(beta / 2.), 12) * (1 + 15 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2));
            else if (n == -5)
                smallD = -(sqrt(4.666666666666667) * pow(cos(beta / 2.), 11) *
                           (3 + (45 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) * sin(beta / 2.));
            else if (n == -4)
                smallD = sqrt(15.166666666666666) * pow(cos(beta / 2.), 10) *
                         (6 + 30 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 2);
            else if (n == -3)
                smallD = -(sqrt(36.4) * pow(cos(beta / 2.), 9) *
                           (10 + (75 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 3));
            else if (n == -2)
                smallD = sqrt(66.73333333333333) * pow(cos(beta / 2.), 8) *
                         (15 + 45 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 4);
            else if (n == -1)
                smallD = -(sqrt(95.33333333333333) * pow(cos(beta / 2.), 7) *
                           (21 + (105 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 5));
            else if (n == 0)
                smallD =
                    (sqrt(429) * pow(cos(beta / 2.), 6) *
                     (28 + 60 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 6)) /
                    2.;
            else if (n == 1)
                smallD = -(sqrt(95.33333333333333) * pow(cos(beta / 2.), 5) *
                           (36 + (135 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 7));
            else if (n == 2)
                smallD = sqrt(66.73333333333333) * pow(cos(beta / 2.), 4) *
                         (45 + 75 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 8);
            else if (n == 3)
                smallD = -(sqrt(36.4) * pow(cos(beta / 2.), 3) *
                           (55 + (165 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 9));
            else if (n == 4)
                smallD = sqrt(15.166666666666666) * pow(cos(beta / 2.), 2) *
                         (66 + 90 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 10);
            else if (n == 5)
                smallD = -(sqrt(4.666666666666667) * cos(beta / 2.) *
                           (78 + (195 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 11));
            else if (n == 6)
                smallD =
                    (91 + 105 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 12);
            else if (n == 7)
                smallD = -(sqrt(7.5) * cos(beta / 2.) * (12 + 16 * cos(beta)) * pow(sin(beta / 2.), 13)) / 2.;
            else if (n == 8)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 14);
        } else if (m == -5) {
            if (n == -8)
                smallD = 4 * sqrt(35) * pow(cos(beta / 2.), 13) * pow(sin(beta / 2.), 3);
            else if (n == -7)
                smallD =
                    (sqrt(35) * pow(cos(beta / 2.), 12) * (-10 + 16 * cos(beta)) * pow(sin(beta / 2.), 2)) /
                    2.;
            else if (n == -6)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 11) *
                         (3 + (45 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) * sin(beta / 2.);
            else if (n == -5)
                smallD = pow(cos(beta / 2.), 10) *
                         (1 + 21 * (-1 + cos(beta)) + (315 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3));
            else if (n == -4)
                smallD = -(sqrt(13) * pow(cos(beta / 2.), 9) *
                           (4 + 42 * (-1 + cos(beta)) + 105 * pow(-1 + cos(beta), 2) +
                            70 * pow(-1 + cos(beta), 3)) *
                           sin(beta / 2.)) /
                         2.;
            else if (n == -3)
                smallD = sqrt(7.8) * pow(cos(beta / 2.), 8) *
                         (10 + 70 * (-1 + cos(beta)) + (525 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 2);
            else if (n == -2)
                smallD = -(sqrt(14.3) * pow(cos(beta / 2.), 7) *
                           (20 + 105 * (-1 + cos(beta)) + (315 * pow(-1 + cos(beta), 2)) / 2. +
                            70 * pow(-1 + cos(beta), 3)) *
                           pow(sin(beta / 2.), 3));
            else if (n == -1)
                smallD = sqrt(20.428571428571427) * pow(cos(beta / 2.), 6) *
                         (35 + 147 * (-1 + cos(beta)) + (735 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = (-3 * sqrt(10.214285714285714) * pow(cos(beta / 2.), 5) *
                          (56 + 196 * (-1 + cos(beta)) + 210 * pow(-1 + cos(beta), 2) +
                           70 * pow(-1 + cos(beta), 3)) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == 1)
                smallD = sqrt(20.428571428571427) * pow(cos(beta / 2.), 4) *
                         (84 + 252 * (-1 + cos(beta)) + (945 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 6);
            else if (n == 2)
                smallD = -(sqrt(14.3) * pow(cos(beta / 2.), 3) *
                           (120 + 315 * (-1 + cos(beta)) + (525 * pow(-1 + cos(beta), 2)) / 2. +
                            70 * pow(-1 + cos(beta), 3)) *
                           pow(sin(beta / 2.), 7));
            else if (n == 3)
                smallD = sqrt(7.8) * pow(cos(beta / 2.), 2) *
                         (165 + 385 * (-1 + cos(beta)) + (1155 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 8);
            else if (n == 4)
                smallD = -(sqrt(13) * cos(beta / 2.) *
                           (220 + 462 * (-1 + cos(beta)) + 315 * pow(-1 + cos(beta), 2) +
                            70 * pow(-1 + cos(beta), 3)) *
                           pow(sin(beta / 2.), 9)) /
                         2.;
            else if (n == 5)
                smallD = (286 + 546 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 10);
            else if (n == 6)
                smallD = -(sqrt(4.666666666666667) * cos(beta / 2.) *
                           (78 + (195 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 11));
            else if (n == 7)
                smallD =
                    (sqrt(35) * pow(cos(beta / 2.), 2) * (10 + 16 * cos(beta)) * pow(sin(beta / 2.), 12)) /
                    2.;
            else if (n == 8)
                smallD = -4 * sqrt(35) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 13);
        } else if (m == -4) {
            if (n == -8)
                smallD = 2 * sqrt(455) * pow(cos(beta / 2.), 12) * pow(sin(beta / 2.), 4);
            else if (n == -7)
                smallD =
                    (sqrt(455) * pow(cos(beta / 2.), 11) * (-8 + 16 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    4.;
            else if (n == -6)
                smallD = sqrt(15.166666666666666) * pow(cos(beta / 2.), 10) *
                         (6 + 30 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 2);
            else if (n == -5)
                smallD = (sqrt(13) * pow(cos(beta / 2.), 9) *
                          (4 + 42 * (-1 + cos(beta)) + 105 * pow(-1 + cos(beta), 2) +
                           70 * pow(-1 + cos(beta), 3)) *
                          sin(beta / 2.)) /
                         2.;
            else if (n == -4)
                smallD = pow(cos(beta / 2.), 8) *
                         (1 + 26 * (-1 + cos(beta)) + (273 * pow(-1 + cos(beta), 2)) / 2. +
                          (455 * pow(-1 + cos(beta), 3)) / 2. + (455 * pow(-1 + cos(beta), 4)) / 4.);
            else if (n == -3)
                smallD = -2 * sqrt(0.6) * pow(cos(beta / 2.), 7) *
                         (5 + 65 * (-1 + cos(beta)) + (455 * pow(-1 + cos(beta), 2)) / 2. +
                          (2275 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         sin(beta / 2.);
            else if (n == -2)
                smallD = sqrt(4.4) * pow(cos(beta / 2.), 6) *
                         (15 + 130 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 4. +
                          (1365 * pow(-1 + cos(beta), 3)) / 4. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -1)
                smallD = -2 * sqrt(1.5714285714285714) * pow(cos(beta / 2.), 5) *
                         (35 + (455 * (-1 + cos(beta))) / 2. + (1911 * pow(-1 + cos(beta), 2)) / 4. +
                          (3185 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 0)
                smallD = 3 * sqrt(0.7857142857142857) * pow(cos(beta / 2.), 4) *
                         (70 + 364 * (-1 + cos(beta)) + 637 * pow(-1 + cos(beta), 2) +
                          455 * pow(-1 + cos(beta), 3) + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD = -2 * sqrt(1.5714285714285714) * pow(cos(beta / 2.), 3) *
                         (126 + 546 * (-1 + cos(beta)) + 819 * pow(-1 + cos(beta), 2) +
                          (4095 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 2)
                smallD = sqrt(4.4) * pow(cos(beta / 2.), 2) *
                         (210 + 780 * (-1 + cos(beta)) + (4095 * pow(-1 + cos(beta), 2)) / 4. +
                          (2275 * pow(-1 + cos(beta), 3)) / 4. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 3)
                smallD = -2 * sqrt(0.6) * cos(beta / 2.) *
                         (330 + (2145 * (-1 + cos(beta))) / 2. + (5005 * pow(-1 + cos(beta), 2)) / 4. +
                          (5005 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 7);
            else if (n == 4)
                smallD = (495 + 1430 * (-1 + cos(beta)) + (3003 * pow(-1 + cos(beta), 2)) / 2. +
                          (1365 * pow(-1 + cos(beta), 3)) / 2. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 8);
            else if (n == 5)
                smallD = -(sqrt(13) * cos(beta / 2.) *
                           (220 + 462 * (-1 + cos(beta)) + 315 * pow(-1 + cos(beta), 2) +
                            70 * pow(-1 + cos(beta), 3)) *
                           pow(sin(beta / 2.), 9)) /
                         2.;
            else if (n == 6)
                smallD = sqrt(15.166666666666666) * pow(cos(beta / 2.), 2) *
                         (66 + 90 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 10);
            else if (n == 7)
                smallD =
                    -(sqrt(455) * pow(cos(beta / 2.), 3) * (8 + 16 * cos(beta)) * pow(sin(beta / 2.), 11)) /
                    4.;
            else if (n == 8)
                smallD = 2 * sqrt(455) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 12);
        } else if (m == -3) {
            if (n == -8)
                smallD = 4 * sqrt(273) * pow(cos(beta / 2.), 11) * pow(sin(beta / 2.), 5);
            else if (n == -7)
                smallD =
                    (sqrt(273) * pow(cos(beta / 2.), 10) * (-6 + 16 * cos(beta)) * pow(sin(beta / 2.), 4)) /
                    2.;
            else if (n == -6)
                smallD = sqrt(36.4) * pow(cos(beta / 2.), 9) *
                         (10 + (75 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 3);
            else if (n == -5)
                smallD = sqrt(7.8) * pow(cos(beta / 2.), 8) *
                         (10 + 70 * (-1 + cos(beta)) + (525 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 2);
            else if (n == -4)
                smallD = 2 * sqrt(0.6) * pow(cos(beta / 2.), 7) *
                         (5 + 65 * (-1 + cos(beta)) + (455 * pow(-1 + cos(beta), 2)) / 2. +
                          (2275 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         sin(beta / 2.);
            else if (n == -3)
                smallD =
                    pow(cos(beta / 2.), 6) *
                    (1 + 30 * (-1 + cos(beta)) + 195 * pow(-1 + cos(beta), 2) + 455 * pow(-1 + cos(beta), 3) +
                     (6825 * pow(-1 + cos(beta), 4)) / 16. + (273 * pow(-1 + cos(beta), 5)) / 2.);
            else if (n == -2)
                smallD = -(sqrt(1.8333333333333333) * pow(cos(beta / 2.), 5) *
                           (6 + 90 * (-1 + cos(beta)) + 390 * pow(-1 + cos(beta), 2) +
                            (1365 * pow(-1 + cos(beta), 3)) / 2. + (4095 * pow(-1 + cos(beta), 4)) / 8. +
                            (273 * pow(-1 + cos(beta), 5)) / 2.) *
                           sin(beta / 2.));
            else if (n == -1)
                smallD = sqrt(2.619047619047619) * pow(cos(beta / 2.), 4) *
                         (21 + 210 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 2. +
                          (1911 * pow(-1 + cos(beta), 3)) / 2. + (9555 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = -(sqrt(11.785714285714286) * pow(cos(beta / 2.), 3) *
                           (56 + 420 * (-1 + cos(beta)) + 1092 * pow(-1 + cos(beta), 2) +
                            1274 * pow(-1 + cos(beta), 3) + (1365 * pow(-1 + cos(beta), 4)) / 2. +
                            (273 * pow(-1 + cos(beta), 5)) / 2.) *
                           pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 1)
                smallD = sqrt(2.619047619047619) * pow(cos(beta / 2.), 2) *
                         (126 + 756 * (-1 + cos(beta)) + 1638 * pow(-1 + cos(beta), 2) +
                          1638 * pow(-1 + cos(beta), 3) + (12285 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD = -(sqrt(1.8333333333333333) * cos(beta / 2.) *
                           (252 + 1260 * (-1 + cos(beta)) + 2340 * pow(-1 + cos(beta), 2) +
                            (4095 * pow(-1 + cos(beta), 3)) / 2. + (6825 * pow(-1 + cos(beta), 4)) / 8. +
                            (273 * pow(-1 + cos(beta), 5)) / 2.) *
                           pow(sin(beta / 2.), 5));
            else if (n == 3)
                smallD = (462 + 1980 * (-1 + cos(beta)) + (6435 * pow(-1 + cos(beta), 2)) / 2. +
                          (5005 * pow(-1 + cos(beta), 3)) / 2. + (15015 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 4)
                smallD = -2 * sqrt(0.6) * cos(beta / 2.) *
                         (330 + (2145 * (-1 + cos(beta))) / 2. + (5005 * pow(-1 + cos(beta), 2)) / 4. +
                          (5005 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 7);
            else if (n == 5)
                smallD = sqrt(7.8) * pow(cos(beta / 2.), 2) *
                         (165 + 385 * (-1 + cos(beta)) + (1155 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 8);
            else if (n == 6)
                smallD = -(sqrt(36.4) * pow(cos(beta / 2.), 3) *
                           (55 + (165 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 9));
            else if (n == 7)
                smallD =
                    (sqrt(273) * pow(cos(beta / 2.), 4) * (6 + 16 * cos(beta)) * pow(sin(beta / 2.), 10)) /
                    2.;
            else if (n == 8)
                smallD = -4 * sqrt(273) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 11);
        } else if (m == -2) {
            if (n == -8)
                smallD = 2 * sqrt(2002) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 6);
            else if (n == -7)
                smallD =
                    (sqrt(500.5) * pow(cos(beta / 2.), 9) * (-4 + 16 * cos(beta)) * pow(sin(beta / 2.), 5)) /
                    2.;
            else if (n == -6)
                smallD = sqrt(66.73333333333333) * pow(cos(beta / 2.), 8) *
                         (15 + 45 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 4);
            else if (n == -5)
                smallD = sqrt(14.3) * pow(cos(beta / 2.), 7) *
                         (20 + 105 * (-1 + cos(beta)) + (315 * pow(-1 + cos(beta), 2)) / 2. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 3);
            else if (n == -4)
                smallD = sqrt(4.4) * pow(cos(beta / 2.), 6) *
                         (15 + 130 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 4. +
                          (1365 * pow(-1 + cos(beta), 3)) / 4. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -3)
                smallD = sqrt(1.8333333333333333) * pow(cos(beta / 2.), 5) *
                         (6 + 90 * (-1 + cos(beta)) + 390 * pow(-1 + cos(beta), 2) +
                          (1365 * pow(-1 + cos(beta), 3)) / 2. + (4095 * pow(-1 + cos(beta), 4)) / 8. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         sin(beta / 2.);
            else if (n == -2)
                smallD = pow(cos(beta / 2.), 4) *
                         (1 + 33 * (-1 + cos(beta)) + (495 * pow(-1 + cos(beta), 2)) / 2. +
                          715 * pow(-1 + cos(beta), 3) + (15015 * pow(-1 + cos(beta), 4)) / 16. +
                          (9009 * pow(-1 + cos(beta), 5)) / 16. + (1001 * pow(-1 + cos(beta), 6)) / 8.);
            else if (n == -1)
                smallD = -(sqrt(1.4285714285714286) * pow(cos(beta / 2.), 3) *
                           (7 + (231 * (-1 + cos(beta))) / 2. + (1155 * pow(-1 + cos(beta), 2)) / 2. +
                            (5005 * pow(-1 + cos(beta), 3)) / 4. + (21021 * pow(-1 + cos(beta), 4)) / 16. +
                            (21021 * pow(-1 + cos(beta), 5)) / 32. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                           sin(beta / 2.));
            else if (n == 0)
                smallD = (3 * sqrt(0.7142857142857143) * pow(cos(beta / 2.), 2) *
                          (28 + 308 * (-1 + cos(beta)) + 1155 * pow(-1 + cos(beta), 2) +
                           2002 * pow(-1 + cos(beta), 3) + (7007 * pow(-1 + cos(beta), 4)) / 4. +
                           (3003 * pow(-1 + cos(beta), 5)) / 4. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                          pow(sin(beta / 2.), 2)) /
                         2.;
            else if (n == 1)
                smallD = -(sqrt(1.4285714285714286) * cos(beta / 2.) *
                           (84 + 693 * (-1 + cos(beta)) + 2079 * pow(-1 + cos(beta), 2) +
                            3003 * pow(-1 + cos(beta), 3) + (9009 * pow(-1 + cos(beta), 4)) / 4. +
                            (27027 * pow(-1 + cos(beta), 5)) / 32. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                           pow(sin(beta / 2.), 3));
            else if (n == 2)
                smallD = (210 + 1386 * (-1 + cos(beta)) + 3465 * pow(-1 + cos(beta), 2) +
                          4290 * pow(-1 + cos(beta), 3) + (45045 * pow(-1 + cos(beta), 4)) / 16. +
                          (15015 * pow(-1 + cos(beta), 5)) / 16. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 3)
                smallD = -(sqrt(1.8333333333333333) * cos(beta / 2.) *
                           (252 + 1260 * (-1 + cos(beta)) + 2340 * pow(-1 + cos(beta), 2) +
                            (4095 * pow(-1 + cos(beta), 3)) / 2. + (6825 * pow(-1 + cos(beta), 4)) / 8. +
                            (273 * pow(-1 + cos(beta), 5)) / 2.) *
                           pow(sin(beta / 2.), 5));
            else if (n == 4)
                smallD = sqrt(4.4) * pow(cos(beta / 2.), 2) *
                         (210 + 780 * (-1 + cos(beta)) + (4095 * pow(-1 + cos(beta), 2)) / 4. +
                          (2275 * pow(-1 + cos(beta), 3)) / 4. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == 5)
                smallD = -(sqrt(14.3) * pow(cos(beta / 2.), 3) *
                           (120 + 315 * (-1 + cos(beta)) + (525 * pow(-1 + cos(beta), 2)) / 2. +
                            70 * pow(-1 + cos(beta), 3)) *
                           pow(sin(beta / 2.), 7));
            else if (n == 6)
                smallD = sqrt(66.73333333333333) * pow(cos(beta / 2.), 4) *
                         (45 + 75 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 8);
            else if (n == 7)
                smallD =
                    -(sqrt(500.5) * pow(cos(beta / 2.), 5) * (4 + 16 * cos(beta)) * pow(sin(beta / 2.), 9)) /
                    2.;
            else if (n == 8)
                smallD = 2 * sqrt(2002) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 10);
        } else if (m == -1) {
            if (n == -8)
                smallD = 4 * sqrt(715) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 7);
            else if (n == -7)
                smallD =
                    (sqrt(715) * pow(cos(beta / 2.), 8) * (-2 + 16 * cos(beta)) * pow(sin(beta / 2.), 6)) /
                    2.;
            else if (n == -6)
                smallD = sqrt(95.33333333333333) * pow(cos(beta / 2.), 7) *
                         (21 + (105 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 5);
            else if (n == -5)
                smallD = sqrt(20.428571428571427) * pow(cos(beta / 2.), 6) *
                         (35 + 147 * (-1 + cos(beta)) + (735 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 4);
            else if (n == -4)
                smallD = 2 * sqrt(1.5714285714285714) * pow(cos(beta / 2.), 5) *
                         (35 + (455 * (-1 + cos(beta))) / 2. + (1911 * pow(-1 + cos(beta), 2)) / 4. +
                          (3185 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -3)
                smallD = sqrt(2.619047619047619) * pow(cos(beta / 2.), 4) *
                         (21 + 210 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 2. +
                          (1911 * pow(-1 + cos(beta), 3)) / 2. + (9555 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == -2)
                smallD = sqrt(1.4285714285714286) * pow(cos(beta / 2.), 3) *
                         (7 + (231 * (-1 + cos(beta))) / 2. + (1155 * pow(-1 + cos(beta), 2)) / 2. +
                          (5005 * pow(-1 + cos(beta), 3)) / 4. + (21021 * pow(-1 + cos(beta), 4)) / 16. +
                          (21021 * pow(-1 + cos(beta), 5)) / 32. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                         sin(beta / 2.);
            else if (n == -1)
                smallD = pow(cos(beta / 2.), 2) *
                         (1 + 35 * (-1 + cos(beta)) + (1155 * pow(-1 + cos(beta), 2)) / 4. +
                          (1925 * pow(-1 + cos(beta), 3)) / 2. + (25025 * pow(-1 + cos(beta), 4)) / 16. +
                          (21021 * pow(-1 + cos(beta), 5)) / 16. + (35035 * pow(-1 + cos(beta), 6)) / 64. +
                          (715 * pow(-1 + cos(beta), 7)) / 8.);
            else if (n == 0)
                smallD = (-3 * cos(beta / 2.) *
                          (8 + 140 * (-1 + cos(beta)) + 770 * pow(-1 + cos(beta), 2) +
                           1925 * pow(-1 + cos(beta), 3) + (5005 * pow(-1 + cos(beta), 4)) / 2. +
                           (7007 * pow(-1 + cos(beta), 5)) / 4. + (5005 * pow(-1 + cos(beta), 6)) / 8. +
                           (715 * pow(-1 + cos(beta), 7)) / 8.) *
                          sin(beta / 2.)) /
                         (2. * sqrt(2));
            else if (n == 1)
                smallD = (36 + 420 * (-1 + cos(beta)) + (3465 * pow(-1 + cos(beta), 2)) / 2. +
                          3465 * pow(-1 + cos(beta), 3) + (15015 * pow(-1 + cos(beta), 4)) / 4. +
                          (9009 * pow(-1 + cos(beta), 5)) / 4. + (45045 * pow(-1 + cos(beta), 6)) / 64. +
                          (715 * pow(-1 + cos(beta), 7)) / 8.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = -(sqrt(1.4285714285714286) * cos(beta / 2.) *
                           (84 + 693 * (-1 + cos(beta)) + 2079 * pow(-1 + cos(beta), 2) +
                            3003 * pow(-1 + cos(beta), 3) + (9009 * pow(-1 + cos(beta), 4)) / 4. +
                            (27027 * pow(-1 + cos(beta), 5)) / 32. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                           pow(sin(beta / 2.), 3));
            else if (n == 3)
                smallD = sqrt(2.619047619047619) * pow(cos(beta / 2.), 2) *
                         (126 + 756 * (-1 + cos(beta)) + 1638 * pow(-1 + cos(beta), 2) +
                          1638 * pow(-1 + cos(beta), 3) + (12285 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 4)
                smallD = -2 * sqrt(1.5714285714285714) * pow(cos(beta / 2.), 3) *
                         (126 + 546 * (-1 + cos(beta)) + 819 * pow(-1 + cos(beta), 2) +
                          (4095 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 5)
                smallD = sqrt(20.428571428571427) * pow(cos(beta / 2.), 4) *
                         (84 + 252 * (-1 + cos(beta)) + (945 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 6);
            else if (n == 6)
                smallD = -(sqrt(95.33333333333333) * pow(cos(beta / 2.), 5) *
                           (36 + (135 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 7));
            else if (n == 7)
                smallD =
                    (sqrt(715) * pow(cos(beta / 2.), 6) * (2 + 16 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == 8)
                smallD = -4 * sqrt(715) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 9);
        } else if (m == 0) {
            if (n == -8)
                smallD = 3 * sqrt(1430) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 8);
            else if (n == -7)
                smallD = 6 * sqrt(1430) * pow(cos(beta / 2.), 7) * cos(beta) * pow(sin(beta / 2.), 7);
            else if (n == -6)
                smallD =
                    (sqrt(429) * pow(cos(beta / 2.), 6) *
                     (28 + 60 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 6)) /
                    2.;
            else if (n == -5)
                smallD = (3 * sqrt(10.214285714285714) * pow(cos(beta / 2.), 5) *
                          (56 + 196 * (-1 + cos(beta)) + 210 * pow(-1 + cos(beta), 2) +
                           70 * pow(-1 + cos(beta), 3)) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == -4)
                smallD = 3 * sqrt(0.7857142857142857) * pow(cos(beta / 2.), 4) *
                         (70 + 364 * (-1 + cos(beta)) + 637 * pow(-1 + cos(beta), 2) +
                          455 * pow(-1 + cos(beta), 3) + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -3)
                smallD = (sqrt(11.785714285714286) * pow(cos(beta / 2.), 3) *
                          (56 + 420 * (-1 + cos(beta)) + 1092 * pow(-1 + cos(beta), 2) +
                           1274 * pow(-1 + cos(beta), 3) + (1365 * pow(-1 + cos(beta), 4)) / 2. +
                           (273 * pow(-1 + cos(beta), 5)) / 2.) *
                          pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == -2)
                smallD = (3 * sqrt(0.7142857142857143) * pow(cos(beta / 2.), 2) *
                          (28 + 308 * (-1 + cos(beta)) + 1155 * pow(-1 + cos(beta), 2) +
                           2002 * pow(-1 + cos(beta), 3) + (7007 * pow(-1 + cos(beta), 4)) / 4. +
                           (3003 * pow(-1 + cos(beta), 5)) / 4. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                          pow(sin(beta / 2.), 2)) /
                         2.;
            else if (n == -1)
                smallD = (3 * cos(beta / 2.) *
                          (8 + 140 * (-1 + cos(beta)) + 770 * pow(-1 + cos(beta), 2) +
                           1925 * pow(-1 + cos(beta), 3) + (5005 * pow(-1 + cos(beta), 4)) / 2. +
                           (7007 * pow(-1 + cos(beta), 5)) / 4. + (5005 * pow(-1 + cos(beta), 6)) / 8. +
                           (715 * pow(-1 + cos(beta), 7)) / 8.) *
                          sin(beta / 2.)) /
                         (2. * sqrt(2));
            else if (n == 0)
                smallD = (35 - 1260 * pow(cos(beta), 2) + 6930 * pow(cos(beta), 4) -
                          12012 * pow(cos(beta), 6) + 6435 * pow(cos(beta), 8)) /
                         128.;
            else if (n == 1)
                smallD = (-3 * cos(beta / 2.) *
                          (8 + 140 * (-1 + cos(beta)) + 770 * pow(-1 + cos(beta), 2) +
                           1925 * pow(-1 + cos(beta), 3) + (5005 * pow(-1 + cos(beta), 4)) / 2. +
                           (7007 * pow(-1 + cos(beta), 5)) / 4. + (5005 * pow(-1 + cos(beta), 6)) / 8. +
                           (715 * pow(-1 + cos(beta), 7)) / 8.) *
                          sin(beta / 2.)) /
                         (2. * sqrt(2));
            else if (n == 2)
                smallD = (3 * sqrt(0.7142857142857143) * pow(cos(beta / 2.), 2) *
                          (28 + 308 * (-1 + cos(beta)) + 1155 * pow(-1 + cos(beta), 2) +
                           2002 * pow(-1 + cos(beta), 3) + (7007 * pow(-1 + cos(beta), 4)) / 4. +
                           (3003 * pow(-1 + cos(beta), 5)) / 4. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                          pow(sin(beta / 2.), 2)) /
                         2.;
            else if (n == 3)
                smallD = -(sqrt(11.785714285714286) * pow(cos(beta / 2.), 3) *
                           (56 + 420 * (-1 + cos(beta)) + 1092 * pow(-1 + cos(beta), 2) +
                            1274 * pow(-1 + cos(beta), 3) + (1365 * pow(-1 + cos(beta), 4)) / 2. +
                            (273 * pow(-1 + cos(beta), 5)) / 2.) *
                           pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 4)
                smallD = 3 * sqrt(0.7857142857142857) * pow(cos(beta / 2.), 4) *
                         (70 + 364 * (-1 + cos(beta)) + 637 * pow(-1 + cos(beta), 2) +
                          455 * pow(-1 + cos(beta), 3) + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 5)
                smallD = (-3 * sqrt(10.214285714285714) * pow(cos(beta / 2.), 5) *
                          (56 + 196 * (-1 + cos(beta)) + 210 * pow(-1 + cos(beta), 2) +
                           70 * pow(-1 + cos(beta), 3)) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == 6)
                smallD =
                    (sqrt(429) * pow(cos(beta / 2.), 6) *
                     (28 + 60 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 6)) /
                    2.;
            else if (n == 7)
                smallD = -6 * sqrt(1430) * pow(cos(beta / 2.), 7) * cos(beta) * pow(sin(beta / 2.), 7);
            else if (n == 8)
                smallD = 3 * sqrt(1430) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 8);
        } else if (m == 1) {
            if (n == -8)
                smallD = 4 * sqrt(715) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 9);
            else if (n == -7)
                smallD =
                    (sqrt(715) * pow(cos(beta / 2.), 6) * (2 + 16 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == -6)
                smallD = sqrt(95.33333333333333) * pow(cos(beta / 2.), 5) *
                         (36 + (135 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 7);
            else if (n == -5)
                smallD = sqrt(20.428571428571427) * pow(cos(beta / 2.), 4) *
                         (84 + 252 * (-1 + cos(beta)) + (945 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 6);
            else if (n == -4)
                smallD = 2 * sqrt(1.5714285714285714) * pow(cos(beta / 2.), 3) *
                         (126 + 546 * (-1 + cos(beta)) + 819 * pow(-1 + cos(beta), 2) +
                          (4095 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -3)
                smallD = sqrt(2.619047619047619) * pow(cos(beta / 2.), 2) *
                         (126 + 756 * (-1 + cos(beta)) + 1638 * pow(-1 + cos(beta), 2) +
                          1638 * pow(-1 + cos(beta), 3) + (12285 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -2)
                smallD = sqrt(1.4285714285714286) * cos(beta / 2.) *
                         (84 + 693 * (-1 + cos(beta)) + 2079 * pow(-1 + cos(beta), 2) +
                          3003 * pow(-1 + cos(beta), 3) + (9009 * pow(-1 + cos(beta), 4)) / 4. +
                          (27027 * pow(-1 + cos(beta), 5)) / 32. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                         pow(sin(beta / 2.), 3);
            else if (n == -1)
                smallD = (36 + 420 * (-1 + cos(beta)) + (3465 * pow(-1 + cos(beta), 2)) / 2. +
                          3465 * pow(-1 + cos(beta), 3) + (15015 * pow(-1 + cos(beta), 4)) / 4. +
                          (9009 * pow(-1 + cos(beta), 5)) / 4. + (45045 * pow(-1 + cos(beta), 6)) / 64. +
                          (715 * pow(-1 + cos(beta), 7)) / 8.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 0)
                smallD = (3 * cos(beta / 2.) *
                          (8 + 140 * (-1 + cos(beta)) + 770 * pow(-1 + cos(beta), 2) +
                           1925 * pow(-1 + cos(beta), 3) + (5005 * pow(-1 + cos(beta), 4)) / 2. +
                           (7007 * pow(-1 + cos(beta), 5)) / 4. + (5005 * pow(-1 + cos(beta), 6)) / 8. +
                           (715 * pow(-1 + cos(beta), 7)) / 8.) *
                          sin(beta / 2.)) /
                         (2. * sqrt(2));
            else if (n == 1)
                smallD = pow(cos(beta / 2.), 2) *
                         (1 + 35 * (-1 + cos(beta)) + (1155 * pow(-1 + cos(beta), 2)) / 4. +
                          (1925 * pow(-1 + cos(beta), 3)) / 2. + (25025 * pow(-1 + cos(beta), 4)) / 16. +
                          (21021 * pow(-1 + cos(beta), 5)) / 16. + (35035 * pow(-1 + cos(beta), 6)) / 64. +
                          (715 * pow(-1 + cos(beta), 7)) / 8.);
            else if (n == 2)
                smallD = -(sqrt(1.4285714285714286) * pow(cos(beta / 2.), 3) *
                           (7 + (231 * (-1 + cos(beta))) / 2. + (1155 * pow(-1 + cos(beta), 2)) / 2. +
                            (5005 * pow(-1 + cos(beta), 3)) / 4. + (21021 * pow(-1 + cos(beta), 4)) / 16. +
                            (21021 * pow(-1 + cos(beta), 5)) / 32. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                           sin(beta / 2.));
            else if (n == 3)
                smallD = sqrt(2.619047619047619) * pow(cos(beta / 2.), 4) *
                         (21 + 210 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 2. +
                          (1911 * pow(-1 + cos(beta), 3)) / 2. + (9555 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 4)
                smallD = -2 * sqrt(1.5714285714285714) * pow(cos(beta / 2.), 5) *
                         (35 + (455 * (-1 + cos(beta))) / 2. + (1911 * pow(-1 + cos(beta), 2)) / 4. +
                          (3185 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 5)
                smallD = sqrt(20.428571428571427) * pow(cos(beta / 2.), 6) *
                         (35 + 147 * (-1 + cos(beta)) + (735 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 4);
            else if (n == 6)
                smallD = -(sqrt(95.33333333333333) * pow(cos(beta / 2.), 7) *
                           (21 + (105 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 5));
            else if (n == 7)
                smallD =
                    (sqrt(715) * pow(cos(beta / 2.), 8) * (-2 + 16 * cos(beta)) * pow(sin(beta / 2.), 6)) /
                    2.;
            else if (n == 8)
                smallD = -4 * sqrt(715) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 7);
        } else if (m == 2) {
            if (n == -8)
                smallD = 2 * sqrt(2002) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 10);
            else if (n == -7)
                smallD =
                    (sqrt(500.5) * pow(cos(beta / 2.), 5) * (4 + 16 * cos(beta)) * pow(sin(beta / 2.), 9)) /
                    2.;
            else if (n == -6)
                smallD = sqrt(66.73333333333333) * pow(cos(beta / 2.), 4) *
                         (45 + 75 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 8);
            else if (n == -5)
                smallD = sqrt(14.3) * pow(cos(beta / 2.), 3) *
                         (120 + 315 * (-1 + cos(beta)) + (525 * pow(-1 + cos(beta), 2)) / 2. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 7);
            else if (n == -4)
                smallD = sqrt(4.4) * pow(cos(beta / 2.), 2) *
                         (210 + 780 * (-1 + cos(beta)) + (4095 * pow(-1 + cos(beta), 2)) / 4. +
                          (2275 * pow(-1 + cos(beta), 3)) / 4. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -3)
                smallD = sqrt(1.8333333333333333) * cos(beta / 2.) *
                         (252 + 1260 * (-1 + cos(beta)) + 2340 * pow(-1 + cos(beta), 2) +
                          (4095 * pow(-1 + cos(beta), 3)) / 2. + (6825 * pow(-1 + cos(beta), 4)) / 8. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -2)
                smallD = (210 + 1386 * (-1 + cos(beta)) + 3465 * pow(-1 + cos(beta), 2) +
                          4290 * pow(-1 + cos(beta), 3) + (45045 * pow(-1 + cos(beta), 4)) / 16. +
                          (15015 * pow(-1 + cos(beta), 5)) / 16. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                         pow(sin(beta / 2.), 4);
            else if (n == -1)
                smallD = sqrt(1.4285714285714286) * cos(beta / 2.) *
                         (84 + 693 * (-1 + cos(beta)) + 2079 * pow(-1 + cos(beta), 2) +
                          3003 * pow(-1 + cos(beta), 3) + (9009 * pow(-1 + cos(beta), 4)) / 4. +
                          (27027 * pow(-1 + cos(beta), 5)) / 32. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 0)
                smallD = (3 * sqrt(0.7142857142857143) * pow(cos(beta / 2.), 2) *
                          (28 + 308 * (-1 + cos(beta)) + 1155 * pow(-1 + cos(beta), 2) +
                           2002 * pow(-1 + cos(beta), 3) + (7007 * pow(-1 + cos(beta), 4)) / 4. +
                           (3003 * pow(-1 + cos(beta), 5)) / 4. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                          pow(sin(beta / 2.), 2)) /
                         2.;
            else if (n == 1)
                smallD = sqrt(1.4285714285714286) * pow(cos(beta / 2.), 3) *
                         (7 + (231 * (-1 + cos(beta))) / 2. + (1155 * pow(-1 + cos(beta), 2)) / 2. +
                          (5005 * pow(-1 + cos(beta), 3)) / 4. + (21021 * pow(-1 + cos(beta), 4)) / 16. +
                          (21021 * pow(-1 + cos(beta), 5)) / 32. + (1001 * pow(-1 + cos(beta), 6)) / 8.) *
                         sin(beta / 2.);
            else if (n == 2)
                smallD = pow(cos(beta / 2.), 4) *
                         (1 + 33 * (-1 + cos(beta)) + (495 * pow(-1 + cos(beta), 2)) / 2. +
                          715 * pow(-1 + cos(beta), 3) + (15015 * pow(-1 + cos(beta), 4)) / 16. +
                          (9009 * pow(-1 + cos(beta), 5)) / 16. + (1001 * pow(-1 + cos(beta), 6)) / 8.);
            else if (n == 3)
                smallD = -(sqrt(1.8333333333333333) * pow(cos(beta / 2.), 5) *
                           (6 + 90 * (-1 + cos(beta)) + 390 * pow(-1 + cos(beta), 2) +
                            (1365 * pow(-1 + cos(beta), 3)) / 2. + (4095 * pow(-1 + cos(beta), 4)) / 8. +
                            (273 * pow(-1 + cos(beta), 5)) / 2.) *
                           sin(beta / 2.));
            else if (n == 4)
                smallD = sqrt(4.4) * pow(cos(beta / 2.), 6) *
                         (15 + 130 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 4. +
                          (1365 * pow(-1 + cos(beta), 3)) / 4. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 5)
                smallD = -(sqrt(14.3) * pow(cos(beta / 2.), 7) *
                           (20 + 105 * (-1 + cos(beta)) + (315 * pow(-1 + cos(beta), 2)) / 2. +
                            70 * pow(-1 + cos(beta), 3)) *
                           pow(sin(beta / 2.), 3));
            else if (n == 6)
                smallD = sqrt(66.73333333333333) * pow(cos(beta / 2.), 8) *
                         (15 + 45 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 4);
            else if (n == 7)
                smallD =
                    -(sqrt(500.5) * pow(cos(beta / 2.), 9) * (-4 + 16 * cos(beta)) * pow(sin(beta / 2.), 5)) /
                    2.;
            else if (n == 8)
                smallD = 2 * sqrt(2002) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 6);
        } else if (m == 3) {
            if (n == -8)
                smallD = 4 * sqrt(273) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 11);
            else if (n == -7)
                smallD =
                    (sqrt(273) * pow(cos(beta / 2.), 4) * (6 + 16 * cos(beta)) * pow(sin(beta / 2.), 10)) /
                    2.;
            else if (n == -6)
                smallD = sqrt(36.4) * pow(cos(beta / 2.), 3) *
                         (55 + (165 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 9);
            else if (n == -5)
                smallD = sqrt(7.8) * pow(cos(beta / 2.), 2) *
                         (165 + 385 * (-1 + cos(beta)) + (1155 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 8);
            else if (n == -4)
                smallD = 2 * sqrt(0.6) * cos(beta / 2.) *
                         (330 + (2145 * (-1 + cos(beta))) / 2. + (5005 * pow(-1 + cos(beta), 2)) / 4. +
                          (5005 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 7);
            else if (n == -3)
                smallD = (462 + 1980 * (-1 + cos(beta)) + (6435 * pow(-1 + cos(beta), 2)) / 2. +
                          (5005 * pow(-1 + cos(beta), 3)) / 2. + (15015 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -2)
                smallD = sqrt(1.8333333333333333) * cos(beta / 2.) *
                         (252 + 1260 * (-1 + cos(beta)) + 2340 * pow(-1 + cos(beta), 2) +
                          (4095 * pow(-1 + cos(beta), 3)) / 2. + (6825 * pow(-1 + cos(beta), 4)) / 8. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 5);
            else if (n == -1)
                smallD = sqrt(2.619047619047619) * pow(cos(beta / 2.), 2) *
                         (126 + 756 * (-1 + cos(beta)) + 1638 * pow(-1 + cos(beta), 2) +
                          1638 * pow(-1 + cos(beta), 3) + (12285 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 0)
                smallD = (sqrt(11.785714285714286) * pow(cos(beta / 2.), 3) *
                          (56 + 420 * (-1 + cos(beta)) + 1092 * pow(-1 + cos(beta), 2) +
                           1274 * pow(-1 + cos(beta), 3) + (1365 * pow(-1 + cos(beta), 4)) / 2. +
                           (273 * pow(-1 + cos(beta), 5)) / 2.) *
                          pow(sin(beta / 2.), 3)) /
                         2.;
            else if (n == 1)
                smallD = sqrt(2.619047619047619) * pow(cos(beta / 2.), 4) *
                         (21 + 210 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 2. +
                          (1911 * pow(-1 + cos(beta), 3)) / 2. + (9555 * pow(-1 + cos(beta), 4)) / 16. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 2)
                smallD = sqrt(1.8333333333333333) * pow(cos(beta / 2.), 5) *
                         (6 + 90 * (-1 + cos(beta)) + 390 * pow(-1 + cos(beta), 2) +
                          (1365 * pow(-1 + cos(beta), 3)) / 2. + (4095 * pow(-1 + cos(beta), 4)) / 8. +
                          (273 * pow(-1 + cos(beta), 5)) / 2.) *
                         sin(beta / 2.);
            else if (n == 3)
                smallD =
                    pow(cos(beta / 2.), 6) *
                    (1 + 30 * (-1 + cos(beta)) + 195 * pow(-1 + cos(beta), 2) + 455 * pow(-1 + cos(beta), 3) +
                     (6825 * pow(-1 + cos(beta), 4)) / 16. + (273 * pow(-1 + cos(beta), 5)) / 2.);
            else if (n == 4)
                smallD = -2 * sqrt(0.6) * pow(cos(beta / 2.), 7) *
                         (5 + 65 * (-1 + cos(beta)) + (455 * pow(-1 + cos(beta), 2)) / 2. +
                          (2275 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         sin(beta / 2.);
            else if (n == 5)
                smallD = sqrt(7.8) * pow(cos(beta / 2.), 8) *
                         (10 + 70 * (-1 + cos(beta)) + (525 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 2);
            else if (n == 6)
                smallD = -(sqrt(36.4) * pow(cos(beta / 2.), 9) *
                           (10 + (75 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                           pow(sin(beta / 2.), 3));
            else if (n == 7)
                smallD =
                    (sqrt(273) * pow(cos(beta / 2.), 10) * (-6 + 16 * cos(beta)) * pow(sin(beta / 2.), 4)) /
                    2.;
            else if (n == 8)
                smallD = -4 * sqrt(273) * pow(cos(beta / 2.), 11) * pow(sin(beta / 2.), 5);
        } else if (m == 4) {
            if (n == -8)
                smallD = 2 * sqrt(455) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 12);
            else if (n == -7)
                smallD =
                    (sqrt(455) * pow(cos(beta / 2.), 3) * (8 + 16 * cos(beta)) * pow(sin(beta / 2.), 11)) /
                    4.;
            else if (n == -6)
                smallD = sqrt(15.166666666666666) * pow(cos(beta / 2.), 2) *
                         (66 + 90 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 10);
            else if (n == -5)
                smallD = (sqrt(13) * cos(beta / 2.) *
                          (220 + 462 * (-1 + cos(beta)) + 315 * pow(-1 + cos(beta), 2) +
                           70 * pow(-1 + cos(beta), 3)) *
                          pow(sin(beta / 2.), 9)) /
                         2.;
            else if (n == -4)
                smallD = (495 + 1430 * (-1 + cos(beta)) + (3003 * pow(-1 + cos(beta), 2)) / 2. +
                          (1365 * pow(-1 + cos(beta), 3)) / 2. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 8);
            else if (n == -3)
                smallD = 2 * sqrt(0.6) * cos(beta / 2.) *
                         (330 + (2145 * (-1 + cos(beta))) / 2. + (5005 * pow(-1 + cos(beta), 2)) / 4. +
                          (5005 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 7);
            else if (n == -2)
                smallD = sqrt(4.4) * pow(cos(beta / 2.), 2) *
                         (210 + 780 * (-1 + cos(beta)) + (4095 * pow(-1 + cos(beta), 2)) / 4. +
                          (2275 * pow(-1 + cos(beta), 3)) / 4. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 6);
            else if (n == -1)
                smallD = 2 * sqrt(1.5714285714285714) * pow(cos(beta / 2.), 3) *
                         (126 + 546 * (-1 + cos(beta)) + 819 * pow(-1 + cos(beta), 2) +
                          (4095 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 5);
            else if (n == 0)
                smallD = 3 * sqrt(0.7857142857142857) * pow(cos(beta / 2.), 4) *
                         (70 + 364 * (-1 + cos(beta)) + 637 * pow(-1 + cos(beta), 2) +
                          455 * pow(-1 + cos(beta), 3) + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 4);
            else if (n == 1)
                smallD = 2 * sqrt(1.5714285714285714) * pow(cos(beta / 2.), 5) *
                         (35 + (455 * (-1 + cos(beta))) / 2. + (1911 * pow(-1 + cos(beta), 2)) / 4. +
                          (3185 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 3);
            else if (n == 2)
                smallD = sqrt(4.4) * pow(cos(beta / 2.), 6) *
                         (15 + 130 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 4. +
                          (1365 * pow(-1 + cos(beta), 3)) / 4. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         pow(sin(beta / 2.), 2);
            else if (n == 3)
                smallD = 2 * sqrt(0.6) * pow(cos(beta / 2.), 7) *
                         (5 + 65 * (-1 + cos(beta)) + (455 * pow(-1 + cos(beta), 2)) / 2. +
                          (2275 * pow(-1 + cos(beta), 3)) / 8. + (455 * pow(-1 + cos(beta), 4)) / 4.) *
                         sin(beta / 2.);
            else if (n == 4)
                smallD = pow(cos(beta / 2.), 8) *
                         (1 + 26 * (-1 + cos(beta)) + (273 * pow(-1 + cos(beta), 2)) / 2. +
                          (455 * pow(-1 + cos(beta), 3)) / 2. + (455 * pow(-1 + cos(beta), 4)) / 4.);
            else if (n == 5)
                smallD = -(sqrt(13) * pow(cos(beta / 2.), 9) *
                           (4 + 42 * (-1 + cos(beta)) + 105 * pow(-1 + cos(beta), 2) +
                            70 * pow(-1 + cos(beta), 3)) *
                           sin(beta / 2.)) /
                         2.;
            else if (n == 6)
                smallD = sqrt(15.166666666666666) * pow(cos(beta / 2.), 10) *
                         (6 + 30 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 2);
            else if (n == 7)
                smallD =
                    -(sqrt(455) * pow(cos(beta / 2.), 11) * (-8 + 16 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    4.;
            else if (n == 8)
                smallD = 2 * sqrt(455) * pow(cos(beta / 2.), 12) * pow(sin(beta / 2.), 4);
        } else if (m == 5) {
            if (n == -8)
                smallD = 4 * sqrt(35) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 13);
            else if (n == -7)
                smallD =
                    (sqrt(35) * pow(cos(beta / 2.), 2) * (10 + 16 * cos(beta)) * pow(sin(beta / 2.), 12)) /
                    2.;
            else if (n == -6)
                smallD = sqrt(4.666666666666667) * cos(beta / 2.) *
                         (78 + (195 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 11);
            else if (n == -5)
                smallD = (286 + 546 * (-1 + cos(beta)) + (1365 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 10);
            else if (n == -4)
                smallD = (sqrt(13) * cos(beta / 2.) *
                          (220 + 462 * (-1 + cos(beta)) + 315 * pow(-1 + cos(beta), 2) +
                           70 * pow(-1 + cos(beta), 3)) *
                          pow(sin(beta / 2.), 9)) /
                         2.;
            else if (n == -3)
                smallD = sqrt(7.8) * pow(cos(beta / 2.), 2) *
                         (165 + 385 * (-1 + cos(beta)) + (1155 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 8);
            else if (n == -2)
                smallD = sqrt(14.3) * pow(cos(beta / 2.), 3) *
                         (120 + 315 * (-1 + cos(beta)) + (525 * pow(-1 + cos(beta), 2)) / 2. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 7);
            else if (n == -1)
                smallD = sqrt(20.428571428571427) * pow(cos(beta / 2.), 4) *
                         (84 + 252 * (-1 + cos(beta)) + (945 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 6);
            else if (n == 0)
                smallD = (3 * sqrt(10.214285714285714) * pow(cos(beta / 2.), 5) *
                          (56 + 196 * (-1 + cos(beta)) + 210 * pow(-1 + cos(beta), 2) +
                           70 * pow(-1 + cos(beta), 3)) *
                          pow(sin(beta / 2.), 5)) /
                         2.;
            else if (n == 1)
                smallD = sqrt(20.428571428571427) * pow(cos(beta / 2.), 6) *
                         (35 + 147 * (-1 + cos(beta)) + (735 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 4);
            else if (n == 2)
                smallD = sqrt(14.3) * pow(cos(beta / 2.), 7) *
                         (20 + 105 * (-1 + cos(beta)) + (315 * pow(-1 + cos(beta), 2)) / 2. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 3);
            else if (n == 3)
                smallD = sqrt(7.8) * pow(cos(beta / 2.), 8) *
                         (10 + 70 * (-1 + cos(beta)) + (525 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3)) *
                         pow(sin(beta / 2.), 2);
            else if (n == 4)
                smallD = (sqrt(13) * pow(cos(beta / 2.), 9) *
                          (4 + 42 * (-1 + cos(beta)) + 105 * pow(-1 + cos(beta), 2) +
                           70 * pow(-1 + cos(beta), 3)) *
                          sin(beta / 2.)) /
                         2.;
            else if (n == 5)
                smallD = pow(cos(beta / 2.), 10) *
                         (1 + 21 * (-1 + cos(beta)) + (315 * pow(-1 + cos(beta), 2)) / 4. +
                          70 * pow(-1 + cos(beta), 3));
            else if (n == 6)
                smallD = -(sqrt(4.666666666666667) * pow(cos(beta / 2.), 11) *
                           (3 + (45 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) * sin(beta / 2.));
            else if (n == 7)
                smallD =
                    (sqrt(35) * pow(cos(beta / 2.), 12) * (-10 + 16 * cos(beta)) * pow(sin(beta / 2.), 2)) /
                    2.;
            else if (n == 8)
                smallD = -4 * sqrt(35) * pow(cos(beta / 2.), 13) * pow(sin(beta / 2.), 3);
        } else if (m == 6) {
            if (n == -8)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 14);
            else if (n == -7)
                smallD = (sqrt(7.5) * cos(beta / 2.) * (12 + 16 * cos(beta)) * pow(sin(beta / 2.), 13)) / 2.;
            else if (n == -6)
                smallD =
                    (91 + 105 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 12);
            else if (n == -5)
                smallD = sqrt(4.666666666666667) * cos(beta / 2.) *
                         (78 + (195 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 11);
            else if (n == -4)
                smallD = sqrt(15.166666666666666) * pow(cos(beta / 2.), 2) *
                         (66 + 90 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 10);
            else if (n == -3)
                smallD = sqrt(36.4) * pow(cos(beta / 2.), 3) *
                         (55 + (165 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 9);
            else if (n == -2)
                smallD = sqrt(66.73333333333333) * pow(cos(beta / 2.), 4) *
                         (45 + 75 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 8);
            else if (n == -1)
                smallD = sqrt(95.33333333333333) * pow(cos(beta / 2.), 5) *
                         (36 + (135 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 7);
            else if (n == 0)
                smallD =
                    (sqrt(429) * pow(cos(beta / 2.), 6) *
                     (28 + 60 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 6)) /
                    2.;
            else if (n == 1)
                smallD = sqrt(95.33333333333333) * pow(cos(beta / 2.), 7) *
                         (21 + (105 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 5);
            else if (n == 2)
                smallD = sqrt(66.73333333333333) * pow(cos(beta / 2.), 8) *
                         (15 + 45 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 4);
            else if (n == 3)
                smallD = sqrt(36.4) * pow(cos(beta / 2.), 9) *
                         (10 + (75 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) *
                         pow(sin(beta / 2.), 3);
            else if (n == 4)
                smallD = sqrt(15.166666666666666) * pow(cos(beta / 2.), 10) *
                         (6 + 30 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2)) * pow(sin(beta / 2.), 2);
            else if (n == 5)
                smallD = sqrt(4.666666666666667) * pow(cos(beta / 2.), 11) *
                         (3 + (45 * (-1 + cos(beta))) / 2. + 30 * pow(-1 + cos(beta), 2)) * sin(beta / 2.);
            else if (n == 6)
                smallD = pow(cos(beta / 2.), 12) * (1 + 15 * (-1 + cos(beta)) + 30 * pow(-1 + cos(beta), 2));
            else if (n == 7)
                smallD =
                    -(sqrt(7.5) * pow(cos(beta / 2.), 13) * (-12 + 16 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 8)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 14) * pow(sin(beta / 2.), 2);
        } else if (m == 7) {
            if (n == -8)
                smallD = 4 * cos(beta / 2.) * pow(sin(beta / 2.), 15);
            else if (n == -7)
                smallD = ((14 + 16 * cos(beta)) * pow(sin(beta / 2.), 14)) / 2.;
            else if (n == -6)
                smallD = (sqrt(7.5) * cos(beta / 2.) * (12 + 16 * cos(beta)) * pow(sin(beta / 2.), 13)) / 2.;
            else if (n == -5)
                smallD =
                    (sqrt(35) * pow(cos(beta / 2.), 2) * (10 + 16 * cos(beta)) * pow(sin(beta / 2.), 12)) /
                    2.;
            else if (n == -4)
                smallD =
                    (sqrt(455) * pow(cos(beta / 2.), 3) * (8 + 16 * cos(beta)) * pow(sin(beta / 2.), 11)) /
                    4.;
            else if (n == -3)
                smallD =
                    (sqrt(273) * pow(cos(beta / 2.), 4) * (6 + 16 * cos(beta)) * pow(sin(beta / 2.), 10)) /
                    2.;
            else if (n == -2)
                smallD =
                    (sqrt(500.5) * pow(cos(beta / 2.), 5) * (4 + 16 * cos(beta)) * pow(sin(beta / 2.), 9)) /
                    2.;
            else if (n == -1)
                smallD =
                    (sqrt(715) * pow(cos(beta / 2.), 6) * (2 + 16 * cos(beta)) * pow(sin(beta / 2.), 8)) / 2.;
            else if (n == 0)
                smallD = 6 * sqrt(1430) * pow(cos(beta / 2.), 7) * cos(beta) * pow(sin(beta / 2.), 7);
            else if (n == 1)
                smallD =
                    (sqrt(715) * pow(cos(beta / 2.), 8) * (-2 + 16 * cos(beta)) * pow(sin(beta / 2.), 6)) /
                    2.;
            else if (n == 2)
                smallD =
                    (sqrt(500.5) * pow(cos(beta / 2.), 9) * (-4 + 16 * cos(beta)) * pow(sin(beta / 2.), 5)) /
                    2.;
            else if (n == 3)
                smallD =
                    (sqrt(273) * pow(cos(beta / 2.), 10) * (-6 + 16 * cos(beta)) * pow(sin(beta / 2.), 4)) /
                    2.;
            else if (n == 4)
                smallD =
                    (sqrt(455) * pow(cos(beta / 2.), 11) * (-8 + 16 * cos(beta)) * pow(sin(beta / 2.), 3)) /
                    4.;
            else if (n == 5)
                smallD =
                    (sqrt(35) * pow(cos(beta / 2.), 12) * (-10 + 16 * cos(beta)) * pow(sin(beta / 2.), 2)) /
                    2.;
            else if (n == 6)
                smallD = (sqrt(7.5) * pow(cos(beta / 2.), 13) * (-12 + 16 * cos(beta)) * sin(beta / 2.)) / 2.;
            else if (n == 7)
                smallD = (pow(cos(beta / 2.), 14) * (-14 + 16 * cos(beta))) / 2.;
            else if (n == 8)
                smallD = -4 * pow(cos(beta / 2.), 15) * sin(beta / 2.);
        } else if (m == 8) {
            if (n == -8)
                smallD = pow(sin(beta / 2.), 16);
            else if (n == -7)
                smallD = 4 * cos(beta / 2.) * pow(sin(beta / 2.), 15);
            else if (n == -6)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 2) * pow(sin(beta / 2.), 14);
            else if (n == -5)
                smallD = 4 * sqrt(35) * pow(cos(beta / 2.), 3) * pow(sin(beta / 2.), 13);
            else if (n == -4)
                smallD = 2 * sqrt(455) * pow(cos(beta / 2.), 4) * pow(sin(beta / 2.), 12);
            else if (n == -3)
                smallD = 4 * sqrt(273) * pow(cos(beta / 2.), 5) * pow(sin(beta / 2.), 11);
            else if (n == -2)
                smallD = 2 * sqrt(2002) * pow(cos(beta / 2.), 6) * pow(sin(beta / 2.), 10);
            else if (n == -1)
                smallD = 4 * sqrt(715) * pow(cos(beta / 2.), 7) * pow(sin(beta / 2.), 9);
            else if (n == 0)
                smallD = 3 * sqrt(1430) * pow(cos(beta / 2.), 8) * pow(sin(beta / 2.), 8);
            else if (n == 1)
                smallD = 4 * sqrt(715) * pow(cos(beta / 2.), 9) * pow(sin(beta / 2.), 7);
            else if (n == 2)
                smallD = 2 * sqrt(2002) * pow(cos(beta / 2.), 10) * pow(sin(beta / 2.), 6);
            else if (n == 3)
                smallD = 4 * sqrt(273) * pow(cos(beta / 2.), 11) * pow(sin(beta / 2.), 5);
            else if (n == 4)
                smallD = 2 * sqrt(455) * pow(cos(beta / 2.), 12) * pow(sin(beta / 2.), 4);
            else if (n == 5)
                smallD = 4 * sqrt(35) * pow(cos(beta / 2.), 13) * pow(sin(beta / 2.), 3);
            else if (n == 6)
                smallD = 2 * sqrt(30) * pow(cos(beta / 2.), 14) * pow(sin(beta / 2.), 2);
            else if (n == 7)
                smallD = 4 * pow(cos(beta / 2.), 15) * sin(beta / 2.);
            else if (n == 8)
                smallD = pow(cos(beta / 2.), 16);
        }
    } else {
        throw std::runtime_error("Error: small d wigner of order L,m,n =" + std::to_string(L) + ", " +
                                 std::to_string(m) + ", " + std::to_string(n) + " not available");
    }

    return smallD;
}

double wignerDReal(int L, int m, int n, double alpha, double beta, double gamma) {

    return cos(m * alpha + n * gamma) * smallWignerD(L, m, n, beta);
}

// Using notation that D = Exp(-i m alpha -i n gamma) d(beta)
double wignerDImag(int L, int m, int n, double alpha, double beta, double gamma) {

    return -sin(m * alpha + n * gamma) * smallWignerD(L, m, n, beta);
}
