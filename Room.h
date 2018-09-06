#pragma once
using namespace std;
#include <string>
#include <typeinfo>
#include "Hazard.h"
#include "MushMush.h"
#include "Pit.h"
#include "Bat.h"



class Hazard;

#pragma pack(push, 1)
class Room
{
private:
	int _tunnels[3];
protected:
	const Hazard* _hazard;
public:
	//Ctor Dtor
	Room(int tunnel1, int tunnel2, int tunnel3);
	~Room();

	//getters setter
	int getTunnel1() const;
	int getTunnel2() const;
	int getTunnel3() const;
	void setHazard(const string& eventName);

	int getT1() const;
	int getT2() const;
	int getT3() const;

	//int haveTunnel

	//func
	std::string roomHazard() const;
	const Hazard* getHazard() const;
	bool haveTunnel(int index);
	void deleteHazard();

	//virtual func
	virtual bool attackInRoom(std::string& message) const;
	bool clashInRoom(std::string& msg) const;
	virtual bool roomIsEmpty() const;
	virtual bool isMushMushHere() const;
};
#pragma pack(pop)