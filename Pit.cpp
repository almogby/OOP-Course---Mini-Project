#include "Pit.h"

bool Pit::attackInRoom(std::string & message) const
{
	if (message == "Pit is near")
	{
		message = "Pit is whistling";
		return 1;
	}
	else
	{
		message = "";
		return 0;
	}
}

bool Pit::clashInRoom(std::string & msg) const
{
	if (msg == "Pit is near")
	{
		msg = "You fell into a Pit";
		return 1;
	}
}

bool Pit::isMushMushHere() const
{
	return false;
}
