#include "RegularRoom.h"


RegularRoom::RegularRoom(int tunnel1, int tunnel2, int tunnel3):Room(tunnel1, tunnel2, tunnel3)
{
}

RegularRoom::~RegularRoom()
{
	delete this->_hazard;
}










