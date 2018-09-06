#pragma once
using namespace std;
#include <string>
#include <typeinfo>
#include "Room.h"
#include "SealedRoom.h"
#include "RegularRoom.h"

class Room;
class Cave
{
private:
	Room* _rooms[20];
	int _currentLocation;
	bool _playerWin;
	bool _attack;
public:
	//Ctor Dtor
	Cave(const int* const sealedRooms, int size);
	~Cave();

	//getter setter
	const Room* getRoomAtIndex(int index) const;
	void setCurrentLocation(int index);

	//func
	void plotHazard(int idx, const std::string& eventName);
	void plotPlayerIdx(int idx);
	int findMushMush(void) const;
	void movePlayer(int idx);
	std::string playerAttack(int idx);
	std::string playerClash(int idx);
	bool gameOver() const;
	void hazardNearPlayer(std::string* hazards) const;
};
