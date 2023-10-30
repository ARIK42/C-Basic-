// Abdul Rehman Ishaq Khan - Assignment
#include <iostream>
using namespace std;


int Instructions()
{
	int flag; //flag is a pre-defined value set in place for the while loop to run 
	         //until a condition is met, which breaks the loop
	
		cout << "\n**************************** MENU *******************************\n";
		cout << "\n\tEnter '1' to show menu\n\tEnter '2' to take order\n";
		cout << "\tEnter '3' to show total amount of cups sold\n\tEnter '4' to show total volume of coffee sold\n";
		cout << "\tEnter '5' to show total money made\n\tEnter '0' if you want to exit\n";
		cout << "\n*****************************************************************\n";

	while (1 > 0)
	{
		cout << "\nEnter value: ";
		cin >> flag;
		
		switch (flag)
		{
			case 1:
				cout << "\n***************** WELCOME T0 ROSEBARISTA COFFEE *****************\n\n"; 
				cout << "\t[S] Small coffee cup (9 oz.) - RM 1.75\n\t[M] Medium coffee cup (12 oz.) - RM 1.90\n";
				cout << "\t[L] Large coffee cup (15 oz.) - RM 2.00\n";
				cout << "\n*****************************************************************\n";
				break;
			case 2:
				return 2;
			case 3:
				return 3;
			case 4:
				return 4;
			case 5:
				return 5;
			case 0:
				return 6;
			default:
				cout << "\nInvalid number. Enter a valid number\n";
		}
	}
}

void Buy(int &small, int &medium, int &large) //the parameters are passed here by memory referencing 
{
	int flag1 = 0, count = 0; //flag1 runs the while loop
  	char size, flag2; //flag2 changes the value of flag1 when conditions are met 
	                  //in order to break the while loop
  	
	while (flag1 == 0)
	{
		cout << "\nEnter 'S' for Small; 'M' for Medium; 'L' for Large cup: ";
		cin >> size;
		
		switch (toupper(size)) //converts characters to uppercase for further comparision
		{
			case 'S':
				cout << "\nEnter the number of small cups wanted: ";
				cin >> count;
				small += count;
				break;
			case 'M':
				cout << "\nEnter the number of medium cup(s) wanted: ";
				cin >> count;
				medium += count;
				break;
			case 'L':
				cout << "\nEnter the number of large cup(s) wanted: ";
				cin >> count;
				large += count;
				break;
			default:
				cout << "\nInvalid letter\n";
		}
		
		cout << "\nDo you want to order more? (Y/N): ";
		cin >> flag2;
		
		if (flag2 == 'N' || flag2 == 'n')
		{
			flag1 ++;
		}
	}
}
 	
void Count(int &small, int &medium, int &large) 
{
	cout << "\nTotal small cups sold: " << small << endl;
	cout << "Total medium cups sold: " << medium << endl;
	cout << "Total large cups sold: " << large << endl;
}

double Volume(int &small, int &medium, int &large) 
{
	double volume = 0;
	
	volume += (small*9) + (medium*12) + (large*15);
	cout << endl;
	return volume; //since the output of this function is a single variable unlike Amount() 
	               //which has 3 different values, the value is directly returned
}

double Money(int &small, int &medium, int &large)
{
	double total = 0;
	total += (small*1.75) + (medium*1.90) + (large*2.0);
	cout << endl;
	return total;
}

int main()
{
	int Return, flag = 1, small = 0, medium = 0, large = 0; 
	while (flag == 1)
	{
		Return = Instructions(); //a variable used to store the return value of a 
		                         //function for comparision and manipulation
		switch (Return)
		{
		case 2:
			Buy(small, medium, large);
			break;
		case 3:
			Count(small, medium, large);
			break;
		case 4:
			cout <<"Total Volume of coffee sold: "<< Volume(small, medium, large) <<" oz."<< endl;
			break;
		case 5:
			cout <<"Total money made: RM "<< Money(small, medium, large) << endl; 
			break;
		case 6:
			flag ++;
			break;
		}
	}	
	return 0;
}


