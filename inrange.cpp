/* inrange, A tool that reads numbers from stdin and outputs them to      *
 *               stdout only if they are within a specific range          *
 * Copyright (C) 2019  Ralf Stemmer (ralf.stemmer@gmx.net)                *
 *                                                                        *
 * This program is free software: you can redistribute it and/or modify   *
 * it under the terms of the GNU General Public License as published by   *
 * the Free Software Foundation, either version 3 of the License, or      *
 * (at your option) any later version.                                    *
 *                                                                        *
 * This program is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 * GNU General Public License for more details.                           *
 *                                                                        *
 * You should have received a copy of the GNU General Public License      *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
#include <iostream>
#include <string>
#include <optional>
#include <typeinfo>

// It is easily change the data types used by the tool
// Just change the definition of limit_t to any numeric type
// Or define TYPE in the compilers parameter list
#if defined(TYPE)
typedef TYPE limit_t;
#else
typedef long long limit_t;
#endif


template<typename T> T stox(const std::string &str);
template<> int stox(const std::string &str)
{
    return std::stoi(str);
}
template<> long stox(const std::string &str)
{
    return std::stol(str);
}
template<> long long stox(const std::string &str)
{
    return std::stoll(str);
}
template<> unsigned long stox(const std::string &str)
{
    return std::stoul(str);
}
template<> unsigned long long stox(const std::string &str)
{
    return std::stoull(str);
}
template<> float stox(const std::string &str)
{
    return std::stof(str);
}
template<> double stox(const std::string &str)
{
    return std::stod(str);
}
template<> long double stox(const std::string &str)
{
    return std::stold(str);
}
#define StringToLimit(s) stox<limit_t>(s)



// Parse command line arguments if possible
std::optional<limit_t> ParseLimitArgument(const char *argv)
{
    limit_t limit = 0;

    try
    {
        limit = StringToLimit(argv);
    }
    catch(std::exception &e)
    {
        std::cerr << "Parsing argument \""
                  << argv
                  << "\" failed - only 64bit integer allowed"
                  << std::endl;
        return {};
    }

    return limit;
}



int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cerr << "Invalid number of arguments: "
                  << argv[0]
                  << " lower_limit upper_limit"
                  << std::endl;
        return EXIT_FAILURE;
    }

    // parse arguments
    auto limit1 = ParseLimitArgument(argv[1]);
    auto limit2 = ParseLimitArgument(argv[2]);

    if(!limit1 or !limit2)
        return EXIT_FAILURE;

    // Sort arguments to lower and upper limit
    limit_t lowerlimit;
    limit_t upperlimit;
    if(limit1 < limit2)
    {
        lowerlimit = *limit1;
        upperlimit = *limit2;
    }
    else
    {
        lowerlimit = *limit2;
        upperlimit = *limit1;
    }

#ifdef DEBUG
    std::cout << "lower: " << lowerlimit << std::endl;
    std::cout << "upper: " << upperlimit << std::endl;
#endif

    // Check line by line
    for(std::string line; std::getline(std::cin, line); )
    {
        limit_t value;

        try
        {
            value = StringToLimit(line);
        }
        catch(std::exception &e)
        {
            std::cerr << "Dropping invalid line: " << line << std::endl;
            continue;
        }
    
        if(value >= lowerlimit and value <= upperlimit)
            std::cout << value << std::endl;
    }
    return EXIT_SUCCESS;
}

// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

