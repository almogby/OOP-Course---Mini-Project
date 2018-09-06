#include "Cave.h"

Cave::Cave(const int * const sealedRooms, int size)
{
	this->_playerWin = false;

	this->_rooms[0] = new RegularRoom(2,18,19);
	this->_rooms[1] = new RegularRoom(5, 17, 18);
	this->_rooms[2] = new RegularRoom(0, 4, 17);
	this->_rooms[3] = new RegularRoom(7, 16, 19);
	this->_rooms[4] = new RegularRoom(2, 6, 15);
	this->_rooms[5] = new RegularRoom(1, 9, 14);
	this->_rooms[6] = new RegularRoom(4, 8, 13);
	this->_rooms[7] = new RegularRoom(3, 11, 12);
	this->_rooms[8] = new RegularRoom(6, 10, 11);
	this->_rooms[9] = new RegularRoom(5, 10, 13);
	this->_rooms[10] = new RegularRoom(8, 9, 12);
	this->_rooms[11] = new RegularRoom(7, 8, 15);
	this->_rooms[12] = new RegularRoom(7, 10, 14);
	this->_rooms[13] = new RegularRoom(6, 9, 17);
	this->_rooms[14] = new RegularRoom(5, 12, 16);
	this->_rooms[15] = new RegularRoom(4, 11, 19);
	this->_rooms[16] = new RegularRoom(3, 14, 18);
	this->_rooms[17] = new RegularRoom(1, 2, 13);
	this->_rooms[18] = new RegularRoom(0, 1, 16);
	this->_rooms[19] = new RegularRoom(0, 3, 15);	

	int t1, t2, t3;
	for (int i = 0; i < size; i++)
	{
		t1 = this->_rooms[sealedRooms[i]]->getTunnel1();
		t2 = this->_rooms[sealedRooms[i]]->getTunnel2();
		t3 = this->_rooms[sealedRooms[i]]->getTunnel3();
		this->_rooms[sealedRooms[i]] = new SealedRoom(t1, t2, t3);
	}
/*
int t1, t2, t3;
bool isSealed = false;
for (int i = 0; i < 20; i++)
{
isSealed = false;
if (i % 2 == 0)
{
t1 = i - 2;
t2 = i + 2;
t3 = 19 - i;
}
else
{
t1 = i - 4;
t2 = i + 4;
t3 = 19 - i;
}
for (int j = 0; j < size;j++)
{
if (sealedRooms[j] == i)
{
isSealed = true;
break;
}
}
if (isSealed)
{
_rooms[i] = new SealedRoom(t1, t2, t3);
}
else
{
_rooms[i] = new RegularRoom(t1, t2, t3);
}
}
*/
 	
}

Cave::~Cave()
{
	for (int i = 0; i < 20; i++)
	{
		delete this->_rooms[i];
	}

}

const Room* Cave::getRoomAtIndex(int index) const
{
	if (index < 0 || index > 19)
		throw "Invalid Index Exception";
	return this->_rooms[index];
}

void Cave::setCurrentLocation(int index)
{
	this->_currentLocation = index;	
}



void Cave::plotHazard(int idx, const std::string & eventName)
{
	if (eventName != "MushMush" && eventName != "Pit" && eventName != "Bat")
		throw "Invalid Hazard Exception";

	if (idx < 0 || idx > 19 || this->_rooms[idx]->roomIsEmpty() == 0)
		throw "Invalid Index Exception";

	if (eventName == "MushMush")
	{
		this->_rooms[idx]->setHazard(eventName);
	}
	else if (eventName == "Pit")
	{
		this->_rooms[idx]->setHazard(eventName);
	}
	else if (eventName == "Bat")
	{
		this->_rooms[idx]->setHazard(eventName);
	}	
}

void Cave::plotPlayerIdx(int idx)
{
	if (idx < 0 || idx > 19 || this->_rooms[idx]->roomIsEmpty() == false)
		throw "Invalid Index Exception";

	this->setCurrentLocation(idx);
}

int Cave::findMushMush(void) const
{
	int flagFound = 0, i;
	for (i = 0; i < 20; i++)
	{
		if (this->_rooms[i]->isMushMushHere() == true)
		{
			flagFound = 1;
			break;
		}				
	}
	if (flagFound == 0)
		throw "MushMush Not Found Exception";		
	else
		return i;	
}

void Cave::movePlayer(int idx)
{
	if (idx < 0 || idx > 19)
		throw "Invalid Index Exception";
	if((this->_rooms[this->_currentLocation]->getT1() != idx) && (this->_rooms[this->_currentLocation]->getT2() != idx) && (this->_rooms[this->_currentLocation]->getT3() != idx))
		throw "Invalid Index Exception";
	
	this->_currentLocation = idx;
}

std::string Cave::playerAttack(int idx)
{
	/*
		if(idx < 0 || idx > 19)
		throw "Invalid Index Exception";
	if ((this->_rooms[this->_currentLocation]->getT1() != idx) && (this->_rooms[this->_currentLocation]->getT2() != idx) && (this->_rooms[this->_currentLocation]->getT3() != idx))
		throw "Invalid Index Exception";

	string msg = this->_rooms[idx]->roomHazard();
	if (this->_rooms[idx]->attackInRoom(msg) == 0)
	{
		int i;
		for (i = 0; i < 20; i++)
		{
			if (this->_rooms[i]->isMushMushHere() == 1)
				break;
		}
		int index;
		index = i;
		if (this->_rooms[this->_rooms[index]->getTunnel1()]->roomIsEmpty())
		{
			const string& eventName = "MushMush";
			this->_rooms[this->_rooms[index]->getTunnel1()]->setHazard(eventName);
			this->_rooms[index]->~Room();
		}
		else if (this->_rooms[this->_rooms[index]->getTunnel2()]->roomIsEmpty())
		{
			const string& eventName = "MushMush";
			this->_rooms[this->_rooms[index]->getTunnel2()]->setHazard(eventName);
			this->_rooms[index]->~Room();
		}
		else if (this->_rooms[this->_rooms[index]->getTunnel3()]->roomIsEmpty())
		{
			const string& eventName = "MushMush";
			this->_rooms[this->_rooms[index]->getTunnel3()]->setHazard(eventName);
			this->_rooms[index]->~Room();
		}
	}
	else
	{
		this->_currentLocation = this->findMushMush();
		this->_playerWin = true;
		return msg;
	}
	*/
	
	if (idx < 0 || idx > 19)
		throw "Invalid Index Exception";
	if ((this->_rooms[this->_currentLocation]->getT1() != idx) && (this->_rooms[this->_currentLocation]->getT2() != idx) && (this->_rooms[this->_currentLocation]->getT3() != idx))
		throw "Invalid Index Exception";

	int tun1, tun2, tun3, roomMushMush;

	string msgHazard;
	msgHazard = this->_rooms[idx]->roomHazard();

	if (this->_rooms[this->_currentLocation]->haveTunnel(idx) == true)
	{
		this->_attack = true;
		if (this->_rooms[idx]->isMushMushHere() == true)
		{
			this->_playerWin = true;
			//gameOver();
			return "You got MushMush";
		}
		else if (typeid(this->_rooms[idx]) == typeid(SealedRoom))
		{
			this->_playerWin = false;
			//gameOver();
			return "You just shot yourself";
		}
		else
		{
			tun1 = this->_rooms[idx]->getT1();
			tun2 = this->_rooms[idx]->getT2();
			tun2 = this->_rooms[idx]->getT3();

			if (this->_rooms[tun1]->roomIsEmpty() == false || this->_rooms[tun2]->roomIsEmpty() == false || this->_rooms[tun3]->roomIsEmpty() == false)
			{
				tun1 = this->_rooms[idx]->getTunnel1();
				tun2 = this->_rooms[idx]->getTunnel2();
				tun2 = this->_rooms[idx]->getTunnel3();

				if (this->_rooms[tun1]->roomIsEmpty() == 1)
					roomMushMush = tun1;
				else if (this->_rooms[tun2]->roomIsEmpty() == 1)
					roomMushMush = tun2;
				else if (this->_rooms[tun3]->roomIsEmpty() == 1)
					roomMushMush = tun3;
			}		
		}
	}
	if (msgHazard == "Bat is near")
		return "Bat is laughing";
	else if (msgHazard == "Pit is near")
		return "Pit is whistling";
	else
		return "";

}

std::string Cave::playerClash(int idx)
{
	if (idx < 0 || idx > 19)
		throw "Invalid Index Exception";
	if (!(this->_rooms[idx]->roomHazard() == "Bat is near"))
	{
		this->_currentLocation = idx;
		string msg = this->_rooms[this->_currentLocation]->roomHazard();
		if (this->_rooms[this->_currentLocation]->clashInRoom(msg))
			this->_playerWin = false;

		return msg;	
	}
	this->_rooms[idx]->deleteHazard();
	this->_currentLocation = idx;

	return this->playerClash(idx + 1);	
}

bool Cave::gameOver() const
{
	/*
	int MushMushidx;
	MushMushidx = this->findMushMush();

	if (this->_currentLocation == MushMushidx)
	return true;
	return false;
	*/
	return this->_playerWin;
}

void Cave::hazardNearPlayer(std::string * hazards) const
{
	int indexRoom1, indexRoom2, indexRoom3; //index for the 3 tunnels to the 3 rooms from current location
	indexRoom1 = this->_rooms[this->_currentLocation]->getTunnel1();
	indexRoom2 = this->_rooms[this->_currentLocation]->getTunnel2();
	indexRoom3 = this->_rooms[this->_currentLocation]->getTunnel3();

	hazards[0] = this->_rooms[indexRoom1]->roomHazard();
	hazards[1] = this->_rooms[indexRoom2]->roomHazard();
	hazards[2] = this->_rooms[indexRoom3]->roomHazard();
}
