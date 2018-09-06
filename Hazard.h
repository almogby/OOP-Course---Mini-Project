#pragma once
using namespace std;
#include <string>
#include <typeinfo>


class Hazard
{
public:
	virtual bool attackInRoom(std::string& message) const = 0;
	virtual bool clashInRoom(std::string& msg) const = 0;
	virtual bool isMushMushHere() const = 0;
};
