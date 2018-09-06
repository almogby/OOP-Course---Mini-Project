#include "MushMush.h"

bool MushMush::attackInRoom(std::string & message) const
{
	if (message == "MushMush is near")
	{
		message = "You got MushMush";
		return 1;
	}
	else
	{
		message = "";
		return 0;
	}	
}

bool MushMush::clashInRoom(std::string & msg) const
{
	if (msg == "MushMush is near")
	{
		msg = "MushMush got you";
		return 1;
	}
}

bool MushMush::isMushMushHere() const
{
	return true;
}










