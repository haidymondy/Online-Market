#include "Rate.h"

void Rate::load()
{
	std::string line1, line2;
	std::ifstream totalf, groupf;
	totalf.open("D:/OnlineMarket/Rate/total.txt");
	groupf.open("D:/OnlineMarket/Rate/group.txt");


	while (getline(totalf, line1), getline(groupf, line2)) {
		rate r;
		r.total = stod(line1);
		r.group = stod(line2);
		rateList.push_back(r);
	}
	totalf.close();
	groupf.close();
}

void Rate::addRate(int loc, int rate)
{
	load();
	int count = 0;
	int T = 0;//total
	int G = 0;//group
	for (auto i : rateList) {
		if (count == loc) {
			T = i.total;
			G = i.group;

			T += rate;
			G++;
			i.total = T;
			i.group = G;
		}
		count++;
	}
	store();
}

double Rate::showRate(int loc)
{
	load();
	int counter = 0;
	double sum = 0;
	for (auto i : rateList) {
		if (counter == loc) {
			sum = (i.total / i.group);
		}
		counter++;
	}
	return round(sum * 100) / 100;//to return 2digitd after mark


}

void Rate::store()
{
	deleting();
	std::fstream total, group;
	total.open("D:/OnlineMarket/Rate/total.txt", std::ios::app);
	group.open("D:/OnlineMarket/Rate/group.txt", std::ios::app);
	for (auto i : rateList)
	{
		std::string t = std::to_string(i.total);
		std::string g = std::to_string(i.group);
		total << t << "\n";
		group << g << "\n";
	}
	total.close();
	group.close();

}

void Rate::deleting()
{
	std::ofstream totalf, groupf;
	totalf.open("C:/Users/User/Desktop/total.txt", std::ofstream::trunc);
	groupf.open("C:/Users/User/Desktop/group.txt", std::ofstream::trunc);
	totalf.close();
	groupf.close();
}
