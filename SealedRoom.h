#pragma once
#include "Room.h"

class SealedRoom :public Room
{
public:
	SealedRoom(int tunnel1, int tunnel2, int tunnel3);
	~SealedRoom();
	//virtual bool attackInRoom(std::string& message) const;
};