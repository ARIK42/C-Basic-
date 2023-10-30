#include <iostream>
using namespace std;
#include<fstream>

int main ()
{
	double rent, maintenance, maintenanceCost,increment;
	double income,profit, maxProfit=0;
	int n, units;
	
	ofstream outFile;
	cout << "Number of units: ";
	cin >> units;
	cout << "Rent for each unit: ";
	cin >> rent;
	cout << "Increment in rent: ";
	cin >> increment;
	cout << "Maintenance cost: ";
	cin >> maintenanceCost;
	outFile.open("apartments.txt");  
	
	for(units; units > 0; units--, rent += increment){
		income = units * rent;
		maintenance = units * maintenanceCost;
		profit = income - maintenance;
	
	if (profit > maxProfit){
		maxProfit = profit;
		n = units;
	}
	
	outFile << rent << " " << units << " " << maintenance << " " << income<< " " << profit << "\n";
	}
	outFile.close();
	cout << "Maximum profit can be achieved when "<<n<<" units are rented out."<< endl;
	return 0;
}
