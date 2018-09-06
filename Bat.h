#pragma once
#include "Hazard.h"
class Bat :public Hazard
{
	public:
		virtual bool attackInRoom(std::string& message) const;
		virtual bool clashInRoom(std::string& msg) const;
		virtual bool isMushMushHere() const;

};
