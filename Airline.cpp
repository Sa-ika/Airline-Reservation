#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Airline{
    private:
        string Flight, Des, Dep;
        int Seats;
        
    public:
        Airline(string flight, string des, string dep, int seats){
            Flight = flight;
            Des = des;
            Dep = dep;
            Seats = seats;
        }
        
        string getFlight(){
            return Flight;
        }
        
        string getDes(){
            return Des;
        }
        
        string getDep(){
            return Dep;
        }
        
        int getSeats(){
            return Seats;
        }
        
        update(string flight){
        	ifstream in("D:/Projects/Flight.txt");
        	ofstream out("D:/Projects/Flight Temp.txt");
        	
        	string line;
        	while(getline(in,line)){
        		int pos = line.find(flight);
        		if(pos != string::npos){
        			int current = Seats - 1;
        			Seats = current;
        			stringstream ss;
        			ss << current;
        			string strCurrent = ss.str();
        			
        			int seatPos = line.find_last_of(':');
        			line.replace(seatPos + 2, string::npos,strCurrent);
				}
				out<<line<<endl;
			}
			out.close();
			in.close();
			remove("D:/Projects/Flight.txt");
			rename("D:/Projects/Flight Temp.txt","D:/Projects/Flight.txt");
			cout << "Seat Reserved Succesfully!"<<endl;
		}
                
};

display(){
	ifstream in("D:/Projects/Flight.txt");
	if(!in){
        cout << "Error: File can't open" << endl;
    }
    else{
    	string line;
    	while(getline(in,line)){
    		cout<<line<<endl;
		}
	}
}

int main(){
    Airline flight1("F101", "UAE", "England", 50);
    Airline flight2("F202", "UAE", "USA", 40);
    Airline flight3("F303", "UAE", "Canada", 2);
    
    ofstream out("D:/Projects/Flight.txt"); // Corrected path
    if(!out){
        cout << "Error: File can't open" << endl;
    }
    else{
        // Writing to file
        out << "\t" <<flight1.getFlight() << " : " << flight1.getDes() << " : " << flight1.getDep() << " : " << flight1.getSeats() << endl;
        out << "\t" <<flight2.getFlight() << " : " << flight2.getDes() << " : " << flight2.getDep() << " : " << flight2.getSeats() << endl;
        out << "\t" <<flight3.getFlight() << " : " << flight3.getDes() << " : " << flight3.getDep() << " : " << flight3.getSeats() << endl;

        cout << "Data Saved Successfully!" << endl;
        out.close();
    }
    
    bool exit = false;
    while(!exit){
    	system("cls");
    	cout<<"\t Welcome To Airline Management System"<<endl;
		cout<<"\t ************************************"<<endl;
		cout<<"\t 1.Reserve A Seat."<<endl;
		cout<<"\t 2.Exit."<<endl;
		cout<<"\t Enter Your Choice: ";
		int val;
		cin>>val;
		
		if(val==1)
		{
			system("cls");
			display();
			string flight;
			cout << "Enter Flight No: ";
			cin >> flight;
			if(flight==flight1.getFlight() && flight1.getSeats() > 0)
			{
				flight1.update(flight);
			}
			else if(flight1.getSeats() <= 0){
				cout << "Sorry, Seats Not Available!" << endl;
			}
			
			if(flight==flight2.getFlight() && flight2.getSeats() > 0)
			{
				flight2.update(flight);
			}
			else if(flight2.getSeats() <= 0){
				cout << "Sorry, Seats Not Available!" << endl;
			}
			
			if(flight==flight3.getFlight() && flight3.getSeats() > 0)
			{
				flight3.update(flight);
			}
			else if(flight3.getSeats() <= 0){
				cout << "Sorry, Seats Not Available!" << endl;
			}
			
			Sleep(5000);		
			}
		else if(val == 2)
		{
			system("cls");
			exit = true;
			cout << "Good Luck!"<< endl;
			Sleep(3000);
		}
	}
    return 0;
}

