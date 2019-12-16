#pragma once
#include <vector>
#include "Code.h"

class GardenDecode
{
public:
	GardenDecode();
	~GardenDecode();
	std::vector<Code> codes;
	void decode();

private:
	void loadData();
	void saveResult();
};

