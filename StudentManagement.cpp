#include<iostream>
#include<fstream>
#include<iomanip>
 
using namespace std;
 
 
 
class student
{
	int idnum;
	char name[32];
	int result;
	char grade;
	void calculate();	
public:
	void getdata();		
	void showdata() const;	
	void show_tabular() const;
	int getIDNum() const;
	int LoadData(int);	
}; 
 
 
void student::calculate()
{

	if(result>84 && result<=100)
		grade='A';
	else if(result>=69)
		grade='B';
	else if(result>59)
		grade='C';
	else if(result>49)
		grade='D';
	else if(result<50)
		grade='F';
}
 
void student::getdata()
{
	cout<<"\n\nEnter student's Name: ";
	cin.ignore();
	cin.getline(name,32);
	cout<<"\nEnter The ID number of the student (non-alphanumeric):";
	cin>>idnum;
	cout<<"\nEnter student's result score: ";
	cin>>result;
	calculate();
}
 
void student::showdata() const
{
	cout<<"\nName: "<<name;
	cout<<"\nID Number: "<<idnum;
	cout<<"\nResult: "<<result;
	cout<<"\nLetter Grade: "<<grade;
}
 
void student::show_tabular() const
{
	cout<<idnum<<setw(15)<<" "<<name<<setw(8)<<result<<setw(6)<<grade<<endl;
}
 
int student::getIDNum() const
{
	return idnum;
}
 
 
 
void SaveStudent();	
void displayAll();	
void Searchdisplay(int);	
void modifyStudent(int);	
void deleteStudent(int);	
void DisplayClassResult();	
void DisplayResult();
		
	
 
 
 
 
void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("AsmData.txt",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}
 
 
 
void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("AsmData.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}
 
 
 
void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("AsmData.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.getIDNum()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}
 
 
 
int student::LoadData(int RecordsNum)
{
	string filename = "AsmData.txt";
	string tmp;
	char c; 
	ifstream inFile; 
	inFile.open(filename.c_str());
	if (!inFile) 
	return -1;/*
	while (!inFile.eof()) 
	{
		getline(inFile, name[RecordsNum], ':');
		inFile>>idnum[RecordsNum];
		inFile>>results[RecordsNum];
		name[RecordsNum].erase(remove(name[RecordsNum].begin(),name[RecordsNum].end(),'\n'),name[RecordsNum].end());
		idnum[RecordsNum].erase(remove(idnum[RecordsNum].begin(),idnum[RecordsNum].end(),'\n'),idnum[RecordsNum].end() );
		RecordsNum++;
	}*/
	RecordsNum--; 
	inFile.close();
	inFile.clear(std::ios_base::goodbit);
	return RecordsNum;
}


const int array_size = 500; 
string name[array_size]; 
int idnum[array_size]; 
int result[array_size];
 
 
 
int main()
{
	char ch;
	int num;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	do
	{
	system("cls");
	cout<<"\n\n\t1.Display All Records to Screen";
	cout<<"\n\n\t2.Import from AsmData.txt File";
	cout<<"\n\n\t3.Insert New Record";
	cout<<"\n\n\t4.Search Record by ID & Save to File";
	cout<<"\n\n\t5.Exit";
	cout<<"\n\n\tPlease Enter Your Choice (1-5): ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	display_all(); break;
	case '2':	//LoadData(); break;
	case '3':	write_student(); break;
	case '4':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
				display_sp(num); break;
	case '5':	exit(0);;
	default:	cout<<"\a"; 
    }
	}while(ch!='5');
 
	return 0;
}
