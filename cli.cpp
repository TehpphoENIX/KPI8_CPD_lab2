#include "model.hpp"
#include <iostream>
#include <string>


class CLIView
{
public:
    static std::string show_value(int key) 
    {
        if (model.find(key) != model.end())
        {
            auto val = model[key];
            return model[key]; 
        }
        else
        {
            return "none";
        }
    }

    static std::string success()
    {
        return "success";
    }
};

class CLIController
{
public:
    static std::string get_value(int key)
    {
        return CLIView::show_value(key);
    }
    static std::string insert_string(int key, std::string value)
    {
        model.insert({key,value});
        return CLIView::success();
    }
};

int main()
{
    while (true) {
        std::string command;
        std::cout << ">";
        std::cin >> command;
        if(command == "get") 
        {
            int key;
            std::cin >> key;
            std::cout << CLIController::get_value(key);
        }
        else if(command == "insert")
        {
            int key;
            std::cin >> key;
            std::string value;
            std::cin >> value;
            std::cout << CLIController::insert_string(key, value);
        }
        else if(command == "exit")
        {
            break;
        }
        else
        {
            std::cerr << "Unknown command " << command << "!";
        }
        std::cout << std::endl;
    }
    std::cout << "exited" << std::endl;
    return 0;
}
