#ifndef LOG
#include "log.hpp"
#define LOG
#endif // !LOG


Request::Request(std::string command)
{
	this->command = command;
}


Request::Request(std::string command, std::string args)
{
	this->command = command;
    std::string tmp;
    for (int i = 0; i < args.size(); ++i) {
        if (args[i] == ' ') {
            if (i != 0) {
                tmp.push_back(args[i]);
                arguments.push_back(tmp);
                tmp.clear();
            }
            while (args[i] == ' ') ++i;
        }
        tmp.push_back(args[i]);
    }
    arguments.push_back(tmp);
}

std::pair<std::string, std::vector<std::string>> Request::data()
{
    return {command,arguments};
}

void Log::add(Request request)
{
    requests.push(request);
}

std::pair<std::string, std::vector<std::string>> Log::get_request()
{
    auto ans = requests.top().data();
    requests.pop();

    return ans;

}
