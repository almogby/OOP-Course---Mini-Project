#include "Bat.h"

bool Bat::attackInRoom(std::string & message) const
{
	if (message == "Bat is near")
	{
		message = "Bat is laughing";
		return 1;
	}
	else
	{
		message = "";
		return 0;
	}
}

bool Bat::clashInRoom(std::string & msg) const
{
	if (msg == "Bat is near")
	{
		msg = "A Bat will move you";
		return 1;
	}
}

bool Bat::isMushMushHere() const
{
	return false;
}
