# inrange
A tool that reads numbers from _stdin_ and outputs them to _stdout_ only if they are within a specific range

# Usage

```sh
cat data.txt | inrange $LOWER $UPPER > data_clean.txt
```

`inrange` reads data line by line from _stdin_.
It expects one number per line.
Invalid lines will be dropped (a warning will be printed to _stderr_).
For each valid line, the tool checks if the value is in a specific range: _value ≥ lower-limit ∧ value ≤ upper-limit_.
If the value is in the defined range, it gets print to _stdout_.

The range is defined by the command line arguments.
It is recommend that the first argument is the lower limit and the second argument the upper limit.
The tool actually checks and swaps the limit if necessary.

The data type of the values get determined when the tool gets built.
See the _Build Options_ section of this readme.
By default, the tool expects integers.


# Build and Install

To compile _inrange_ `clang++` is required.
You may change the compiler to `g++` in the build script.

```sh
# 1. DOWNLOAD

git clone https://github.com/rstemmer/inrange.git
cd inrange

# OPTIONAL: You can edit build.sh for a different data types (see next chapter, default is "long long")
# OPTIONAL: You can edit install.sh for a different installation directory (default is "/usr/local/bin")

# 2. BUILD
./build.sh

# 3. INSTALL
sudo ./install.sh
```

# Build Options

Edit the `build.sh` script to change the data type the tool works with.
Default is `long long` - On a 64bit x86 based Linux machine, this is a 64bit signed integer.

Valid types are: `int`, `long`, `long long`, `unsigned long`, `unsigned long long`, `float`, `double` and `long double`

For details about the data types see the [C++ reference](https://en.cppreference.com/w/cpp/language/types).

