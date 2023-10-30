//Name: 
//ID: 
//Course Code: EGC3113

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() 
{
	Student students[500]; 
	int option, len = 0; 
	
	do{
		cout << "\n ************************* Student Menu *************************";
		cout << "\n\n\t 1. Display All Records to Screen.";
		cout << "\n\t 2. Import from AsmData.txt File.";
		cout << "\n\t 3. Insert New Record.";
		cout << "\n\t 4. Search Record by ID & Save to File.";
		cout << "\n\t 5. Search Records for Lowest Score & Display to Screen.";
		cout << "\n\t 6. Sort All Records by ID.";
		cout << "\n\t 7. Sort All Records by Name.";
		cout << "\n\t 8. Exit.";
		cout << "\n\n Enter a number from the menu: "; 
		cin >> option;
	}
	
	string Name, ID;
	int Result;
	char Grade;

	
	void getLetterGrade(int Score) 
	{
		if (Score > 84 && Score <= 100) { //A = 85 - 100
			Grade = 'A'; 
		} 
		else if (Score > 69) { //B = 70 - 84
			Grade = 'B';
		} 
		else if (Score > 59) { //C = 60 - 69
			Grade = 'C';
		}
		else if (Score > 49) { //D = 50 - 59
			Grade = 'D';
		}
		else if (Score < 50) { //F = 0 - 49
			Grade = 'F'; 
		}
	}
	
	
	void writeRecord(Student students)  
	{
		ofstream myFile("AsmData.txt",ios::app); 
		myFile << students.Name << endl;
		myFile.close(); 	
	
	}
	
	
	void readRecord(Student students[], int& len)
	{
		ifstream myFile; 
		myFile.open("AsmData.txt"); 
		
		if (myFile.fail()) {
			cerr << " Error opening file" << endl;
		}
		myFile >> students[len].Name >> students[len].ID;
	}
	

	void showAllRecords(Student students[], int len) 
	{
		if (len == 0) 
			cout << "\n The Student file is empty.\n";

		else
		{
			for (int c = 0; c < len; c++) 
				cout << left << setw(32) << "\n Student Name: " << students[c].Name 
				<< setw(15) << "\n Student ID: " << endl;
		}
	}

	
	void searchID(Student students[], int len)
	{
		string ID; 
		int found = -1; 

		if (len == 0) 
			cout << "\n The Student file is empty.\n";

		else
		{
			cout << "\n Enter Student ID: ";
			cin >> ID;

			for (int c = 0; c < len; c++)
			{
				if (ID.compare(students[c].ID) == 0) 
				{
					cout << left << setw(32) << "\n Student Name: " << students[c].Name 
						<< setw(15) << "\n Student ID: " << students[c].ID << endl;
					found = c; 
					writeRecord(students[c]); 
					break; 
				}
			}

			if (found == -1) 
				cout << "\n\t ERROR: Student ID: " << ID << " not found.";
		}
	}*/


	void insertRecord(Student students[], int &len)
	{
		cout << "\n Enter Name: ";
		cin >> students[len].ame;
		cout << " Enter ID: ";
		cin >> students[len].ID;
		//students[len].getLetterGrade(students[len].Result); 
		//len++; 
	}


	void searchLowestScore(Student students[], int len) 
	{
		int minScore = students[0].Result;
		int pos = 0; 

		if (len == 0) 	
			cout << "\n ERROR: Empty list. Cannot search for lowest Score student record.\n";

		else
		{
			for (int c = 1; c < len; c++)
			{
				
				if (students[c].Result < minScore) 
				{
					minScore = students[c].Result; 
					pos = c; 
				}
			}

			cout << "\n ****** Student Secured Lowest Score ****** "; 
			cout << left << setw(32) << "\n Enter Student Name (upto 32 characters): " << students[pos].Name
				<< setw(15) << "\n Enter Student ID (upto 15 characters): " << students[pos].ID << setw(3)
				<< "\n Result: " << students[pos].Result
				<< setw(1) << "\n Grade: " << students[pos].Grade << endl;
		}
	}


	void sortID(Student students[], int len) 
	{
		
		if (len == 0) 
			cout << "\n ERROR: Empty list. Cannot sort student record by ID.\n";

		else
		{
			for (int r = 0; r < len; r++) 
			{
				for (int c = 0; c < len - r - 1; c++)
				{
					if (students[c].ID.compare(students[c + 1].ID) > 0) 
					{
						Student temp = students[c];
						students[c] = students[c + 1];
						students[c + 1] = temp;
					}
				}
			}
			showAllRecords(students, len); 
		}
	}


	void sortName(Student students[], int len)
	{
		if (len == 0) 
			cout << "\n ERROR: Empty list. Cannot sort student record by Name.";

		else
		{
			for (int r = 0; r < len; r++) 
			{
				for (int c=0; c<len-r-1; c++) 
				{
					if (students[c].Name.compare(students[c+1].Name) > 0)
					{
						Student temp = students[c];
						students[c] = students[c+1];
						students[c+1] = temp;
					}
				}
			}
			showAllRecords(students, len); 
		}
	}
	
	do 
	{
		switch ()
		{
		case 1:
			students[0].showAllRecords(students, len);
			break;
		case 2:
			students[0].readRecord(students, len);
			break;
		case 3:
			students[0].insertRecord(students, len);
			break;
		case 4:
			students[0].searchID(students, len);
			break;
		case 5:
			students[0].searchLowestScore(students, len);
			break;
		case 6:
			students[0].sortID(students, len);
			break;
		case 7:
			students[0].sortName(students, len);
			break;
		case 8:
			return(0);
		}
	} while (1); 
	return 0;
}



/*
const int array_size =20; 
string name[array_size]; 
string id[array_size]; 
int Results[array_size];

int LoadData(int);

int main()
{
	int index =0;
	int tmpNumOfRecords;
	
	tmpNumOfRecords = LoadData(index); 
	if (tmpNumOfRecords == -1) 
		cout<<"\n\nFailed to Read from AsmData.txt!\n\n";
	
	else
	{
		cout<<"\n\n"<<tmpNumOfRecords - index + 1<<" records imported from AsmData.txt.\n\n"; index = tmpNumOfRecords;
	}
	return 0;
	system("pause");
}


int LoadData(int RecordsNum)
{
	string filename = "AsmData.txt"; 
	string tmp;
	char c; // for storing endl at the end of every line in the data file
	
	ifstream inFile; // the file must be in the same directory as your exe file inFile.open(filename.c_str());
	if (!inFile) // cannot open the file
		return -1;
	while (!inFile.eof()) // reading data from file
	{
		getline(inFile, name[RecordsNum], ':'); 
		inFile>>id[RecordsNum]; 
		inFile>>Results[RecordsNum];
		name[RecordsNum].erase(remove(name[RecordsNum].begin(),name[RecordsNum].end(),'\n'),name[RecordsNum].end()); 
		id[RecordsNum].erase(remove(id[RecordsNum].begin(),id[RecordsNum].end(),'\n'),id[RecordsNum].end() );
		// This line is to test that the data has been read in corrected from the file,
		// you can remove it from your code after testing
		cout<<right<<setw(4)<<RecordsNum+1<<":"<<left<<setw(32)<<name[RecordsNum]; 
		cout<<setw(15)<<id[RecordsNum]<<setw(5)<<right<<Results[RecordsNum]<<"\n";
		RecordsNum++;
	}
	RecordsNum--; // the last line is empty 
	inFile.close(); 
	inFile.clear(std::ios_base::goodbit);
	return RecordsNum;
}*/
