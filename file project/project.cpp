#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
struct student {
	int id;
  	double gpa,age;
	string name;
};
signed main() {
loop:
	student s;
	int choice,idd;
	cout << "\n1 -> Add new Data\n2 -> Show All Data\n3 -> Delete Student Data\n4 -> Update Student Data\nChoice is: ";
	cin >> choice;
	switch (choice) {
	case 1:
	{
		cout<<"\nEnter Student Name: ";
		cin>>s.name;
		cout<<"Enter Student ID: ";
		cin>>s.id;
    	cout<<"Enter Student Age: ";
    	cin>>s.age;
    	cout<<"Enter Student Gpa: ";
    	cin>>s.gpa;
		ofstream file;
		file.open("student.txt",ios::app);
		file<<"\n"<<s.name<<"\n"<<s.id<<"\n"<<s.age<<"\n"<<s.gpa<<"\n";
		file.close();
		goto loop;
		break;
	}
	case 2:
	{
		ifstream file1;
		file1.open("student.txt",ios::binary);
		cout << "\n-----All Students Data-----";
    	file1>>s.name>>s.id>>s.age>>s.gpa;
		while (!file1.eof()) {
		cout<<"\nName :"<<s.name;
      	cout<<"\nID :"<<s.id;
      	cout<<"\nage :"<<s.age;
      	cout<<"\nGPA :"<<s.gpa;
      	cout<<"\n--------------------------\n";
      	file1>>s.name>>s.id>>s.age>>s.gpa;
		}
		file1.close();
		goto loop;
		break;
	}
	case 3:
	{
		cout<<"\nEnter the ID of Student You Want to Delete :";
		cin>>idd;
		ifstream i("student.txt",ios::binary);
		ofstream o("new.txt");
    	i>>s.name>>s.id>>s.age>>s.gpa;		
		while(!i.eof()){
			if(s.id==idd){
				cout<<"\nData Deleted\n";				
			}
			else{
				o<<"\n"<<s.name<<"\n";
				o<<s.id<<"\n";
				o<<s.age<<"\n";
				o<<s.gpa<<"\n";				
			}
    		i>>s.name>>s.id>>s.age>>s.gpa;				
		}
		i.close();
		o.close();
		remove("student.txt");
		rename("new.txt","student.txt");
		goto loop;
		break;
	}
	case 4:
	{	
		double new_gpa,new_age;
		string new_name;
		int new_id;
		cout<<"\nEnter the ID of Student You Want to Update :";
		cin>>idd;
		cout<<"Enter the New Name :";
		cin>>new_name;
		cout<<"Enter the New ID :";
		cin>>new_id;
		cout<<"Enter the New Age :";
		cin>>new_age;
		cout<<"Enter the New GPA :";
		cin>>new_gpa;
		ifstream i("student.txt",ios::binary);
		ofstream o("new.txt");
    	i>>s.name>>s.id>>s.age>>s.gpa;		
		while(!i.eof()){
			if(s.id==idd){
				o<<"\n"<<new_name<<"\n";
				o<<new_id<<"\n";
				o<<new_age<<"\n";
				o<<new_gpa<<"\n";		
			}
			else{
				o<<"\n"<<s.name<<"\n";
				o<<s.id<<"\n";
				o<<s.age<<"\n";
				o<<s.gpa<<"\n";				
			}
    		i>>s.name>>s.id>>s.age>>s.gpa;				
		}
		i.close();
		o.close();
		remove("student.txt");
		rename("new.txt","student.txt");
		cout<<"\nUPTADED DONE :)\n";
		goto loop;
		break;		
	}
	}
}
