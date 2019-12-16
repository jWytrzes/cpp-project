#pragma once
#include <vector>
#include "Plantation.h"

class GardenEncode {
public:
	GardenEncode();
	~GardenEncode();
	std::vector<Plantation> plantations;
	void encode();

private:
	void loadData();
	void saveResult();
};
