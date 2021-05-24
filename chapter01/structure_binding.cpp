#include <iostream>
#include <tuple>
#include <chrono>
#include <vector>
#include <iomanip>

std::pair<int, int> divide_remainder(int divident, int divisor);
std::tuple<std::string, std::chrono::system_clock::time_point, unsigned>
stock_info(const std::string &name);

struct employee {
    unsigned id;
    std::string name;
    std::string role;
    unsigned salary;
};

int main(int argc, char **argv)
{

    /*****************************************************/

    // the old way
    const auto result = divide_remainder(16, 3);
    std::cout << "16 / 3 is "
              << result.first << " with a remainder of "
              << result.second << std::endl;

    // the old way
    int only_remainder;
    std::tie(std::ignore, only_remainder) = divide_remainder(16, 3);

    // the new way
    auto [fraction, remainder] = divide_remainder(16, 3);
    std::cout << "16 / 3 is "
              << fraction << " with a remainder of "
              << remainder << std::endl;

    /*****************************************************/

    const auto [name, valid_time, price] = stock_info("AAPL");
    std::time_t now_c = std::chrono::system_clock::to_time_t(valid_time);
    std::cout << "For your request: "
              << name << " is "
              << price << " at "
              << std::put_time(std::localtime(&now_c), "%F %T") << std::endl;

    /*****************************************************/

    std::vector<employee> employees {};
    for(const auto &[id, name, role, salary] : employees) {
        std::cout << "Name: " << name
                  << "Role: " << role
                  << "Salary: " << salary << std::endl;
    }
        

    return 0;
}

std::pair<int, int> divide_remainder(int divident, int divisor)
{
    return std::pair(divident / divisor, divident % divisor);
}

std::tuple<std::string, std::chrono::system_clock::time_point, unsigned> stock_info(const std::string &name)
{
    return std::tuple(name, std::chrono::system_clock::now(), 100);
}
