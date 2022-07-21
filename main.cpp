#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

void findActor (std::string name)
{
    std::ifstream file("test.json");
    nlohmann::json movieDB;
    file >> movieDB;
    file.close();

    for (nlohmann::json::iterator it_first = movieDB.begin(); it_first != movieDB.end(); ++it_first) {
        nlohmann::json::iterator it_second = it_first.value().find("Cast");
        if (it_second != it_first.value().end())
        {
            nlohmann::json::iterator it_third = it_second.value().find(name);
            if (it_third != it_second.value().end())
            {
                std::cout << it_first.key() << " - " << it_third.value() << std::endl;
            }
        }
    }
}

int main() {
    findActor("Rutger Hauer");
    return 0;
}