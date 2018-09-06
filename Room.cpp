#include "Room.h"
#include "RegularRoom.h"
#include "SealedRoom.h"

Room::Room(int tunnel1, int tunnel2, int tunnel3)
{
	this->_tunnels[0] = tunnel1;
	this->_tunnels[1] = tunnel2;
	this->_tunnels[2] = tunnel3;

	this->_hazard = NULL;
}

Room::~Room()
{
	delete this->_hazard;
}

int Room::getTunnel1() const
{
	int min = 20, i, minIndex;

	for (i = 0; i < 3; i++)
	{
		if (this->_tunnels[i] < min)
		{
			min = this->_tunnels[i];
			minIndex = i;
		}			
	}
	return minIndex;
}

int Room::getTunnel2() const
{
	int midIndex;

	//case midIndex=0
	if (((this->_tunnels[1]<this->_tunnels[0]) && (this->_tunnels[0]<this->_tunnels[2])) || ((this->_tunnels[2]<this->_tunnels[0]) && (this->_tunnels[0]<this->_tunnels[1])))
	{
		midIndex = 0;
		return midIndex;
	} 

	//case midIndex=1
	else if (((this->_tunnels[0]<this->_tunnels[1]) && (this->_tunnels[1]<this->_tunnels[2])) || ((this->_tunnels[2]<this->_tunnels[1]) && (this->_tunnels[1]<this->_tunnels[0])))
	{
		midIndex = 1;
		return midIndex;
	}

	//case midIndex=2
	else if (((this->_tunnels[0]<this->_tunnels[2]) && (this->_tunnels[2]<this->_tunnels[1])) || ((this->_tunnels[1]<this->_tunnels[2]) && (this->_tunnels[2]<this->_tunnels[0])))
	{
		midIndex = 2;
		return midIndex;
	}
}

int Room::getTunnel3() const
{
	int max = -1, i, maxIndex;

	for (i = 0; i < 3; i++)
	{
		if (this->_tunnels[i] > max)
		{
			max = this->_tunnels[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void Room::setHazard(const string & str)
{
	if (!str.compare("MushMush"))
		this->_hazard = new MushMush;
	else if (!str.compare("Bat"))
		this->_hazard = new Bat;
	else if (!str.compare("Pit"))
		this->_hazard = new Pit;
}

std::string Room::roomHazard() const
{
	if(((typeid(this->_hazard) != typeid(MushMush)) && (typeid(this->_hazard) != typeid(Bat)) && (typeid(this->_hazard) != typeid(Pit))))
		return "";
	if(typeid(this->_hazard) == typeid(MushMush))
		return "MushMush is near";
	if (typeid(this->_hazard) == typeid(Bat))
		return "Bat is near";
	else if (typeid(this->_hazard) == typeid(Pit))
		return "Pit is near";

	/*
	if (this->_hazard == NULL)
	return "";
	return this->_hazard->msgRoomHazard();
	*/	
}

const Hazard * Room::getHazard() const
{
	return this->_hazard;
}

bool Room::haveTunnel(int index)
{
	if (index < 0 || index > 19)
		return false;
	if ((this->getT1() != index) && (this->getT2() != index) && (this->getT3() != index))
		throw false;
	return true;
}

void Room::deleteHazard()
{
	delete this->_hazard;
}

bool Room::attackInRoom(std::string & message) const
{
	if (typeid(this) == typeid(RegularRoom))
	{
		return this->_hazard->attackInRoom(message);
	}
	if (typeid(this) == typeid(SealedRoom))
	{
		message = "You just shot yourself";
		return 1;
	}
	else
		return 0;		
}

bool Room::clashInRoom(std::string & msg) const
{
	if ((this->_hazard == NULL) || (typeid(this->_hazard) != typeid(MushMush) && typeid(this->_hazard) != typeid(Bat) && typeid(this->_hazard) != typeid(Pit)))
	{
		msg = "";
		return 0;
	}
	else
		this->_hazard->clashInRoom(msg);
}

bool Room::roomIsEmpty() const
{
	if (((typeid(this->_hazard) != typeid(MushMush) && typeid(this->_hazard) != typeid(Bat) && typeid(this->_hazard) != typeid(Pit))))
		return true;
	return false;
}

bool Room::isMushMushHere() const
{	
	if (this->_hazard != NULL)
	{
		bool result;
		result = this->_hazard->isMushMushHere();
		return result;
	}
	return false;
	/*
	if (this->_hazard != NULL)
	{
	if (typeid(this->_hazard) == typeid(MushMush))
	return true;
	return false;
	}
	return false;
	*/
}

int Room::getT1() const
{
	return this->_tunnels[0];
}

int Room::getT2() const
{
	return this->_tunnels[1];
}

int Room::getT3() const
{
	return this->_tunnels[2];
}




