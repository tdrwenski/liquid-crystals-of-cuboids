CPP=clang++

CPPFLAGS=-c -Wall -std=c++17
LINKFLAGS=

release: CPPFLAGS+=-O3
debug: CPPFLAGS+=-O0 -g -fsanitize=address -fno-omit-frame-pointer
debug: LINKFLAGS+=-g -fsanitize=address -fno-omit-frame-pointer

INC=-I./include
LIB=-lgsl -lgslcblas -lcuba

# Paths
OBJDIR=obj
SRCDIR=src
INCDIR=include
TESTDIR=test
TESTBUILD=test_build

dummy_build_folder := $(shell mkdir -p $(OBJDIR))
test_build_folder := $(shell mkdir -p $(TESTBUILD))

# File lists
#  - SOURCES contains all source files, except main.cpp, so that the derived list OBJECTS can later
#    be used to link other executables.
#  - OBJECTS same list as SOURCES, but now the object files.
#  - EXEC_OBJ is the object file containing main().
SOURCES = $(shell find $(SRCDIR) -name *.cpp -not -name main.cpp)

# For each cpp file, we want to create a single object file.
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXEC_OBJ = $(OBJDIR)/main.o
TEST_OBJ = $(TESTBUILD)/main.o

# Make a rule for all entries in the list OBJECTS.
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling: $< -> $@"
	$(CPP) $(CPPFLAGS) $(INC) $< -o $@

# Make a rule for all tests
$(TESTBUILD)/%.o: $(TESTDIR)/%.cpp
	@echo "Compiling Test: $< -> $@"
	$(CPP) $(CPPFLAGS) $(INC) $< -o $@

# Make rule for executable
all: $(OBJECTS) $(EXEC_OBJ)
	@echo "Linking objects"
	$(CPP) $(LINKFLAGS) $(OBJECTS) $(EXEC_OBJ) $(LIB) -o run

release: all
debug: all

# Make rule for test executable
test: $(OBJECTS) $(TEST_OBJ)
	@echo "Linking test"
	$(CPP) $(LINKFLAGS) $(OBJECTS) $(TEST_OBJ) $(LIB) -lgtest -lgmock -o run_tests

# Cleaning
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TESTBUILD)/*.o


