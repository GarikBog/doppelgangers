#ifndef STRING
#include<string>
#define STRING
#endif // !STRING

#ifndef VECTOR
#include<vector>
#define VECTOR
#endif // !VECTOR





class Request {
private:
	std::string command = "";
	std::vector<std::string> args;

public:
	
	Request(std::string command);
	Request(std::string command, std::string args);

};


class Log {
private:
	std::vector<Request> requests;

public:

	void add(Request request);
	
	std::pair < std::string, std::vector<std::string>> get_request();
	

};