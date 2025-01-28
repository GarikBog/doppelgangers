#ifndef LOG
#include "log.hpp"
#define LOG
#endif // !LOG


Request::Request(std::string command)
{
	this->command = command;
}


Request::Request(std::string command, std::vector<std::string> args)
{
	this->command = command;
    arguments = args;
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
