#pragma once
#include <vector>
#include "Plantation.h"


class GardenEncode
{
public:
	std::vector<Plantation> plantations;
	GardenEncode();
	~GardenEncode();
	void encode();

private:
	void loadData();
	void saveResult();
};

