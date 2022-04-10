//
//  main.cpp
//  Login and Registration System
//
//  Created by MoQuayson on 23/05/2021.
//  Copyright © 2021 MoQuayson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;

//Fuction Delcation
void UserLogin(); // user login
void UserRegistration(); // user register
void UserModify(); // user modification

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int choice;
	//Main Menu
	cout<<"Welcome To MoQuayson Hub\n\n\n";
	cout<<"1: Login To Continue\n";
	cout<<"2: SignUp To Join\n";
	cout<<"3: Modify User Account\n";
	cout<<"4: Delete User Account\n";
	cout<<"0: Exit\n";
	
	cout<<"Enter Choice: ";
	cin>>choice;
	
	//Choice of the User Input
	if(choice == 1)
	{
		UserLogin();
	}
	
	if(choice == 2)
	{
		UserRegistration();
	}
	
	if(choice == 3)
	{
		UserModify();
	}
	
	else{
		system("exit");
	}
	return 0;
}

//Login
void UserLogin()
{
	ifstream userFile;
	char user[100];
	char pass[100];
	char filename[300]="";
	char fileLocation[5000] = "C:/Users/Moses/OneDrive/Documents/Mo Projects/CPP Projects/Login and Registration System/User Accounts/";
	char ext[10] = ".txt";//extension file
	//char txt[100];
	string txt;
	
	cout<<"Login Module\n\n";
	//User Enters ID
	cout<<"Enter Username: ";
	cin>>user;
	
	//User Enters Password
	cout<<"Enter Password: ";
	cin>>pass;
	
	strcat(filename,user); //username
	strcat(filename,ext); //username.txt
	strcat(fileLocation,filename); //assign filename and ext as file location
	
	//Opens and Reads from file
	userFile.open(fileLocation);
	if(userFile.good())
	{
		userFile>>txt;
		
		if(txt == pass)
		{
			cout<<"Success: Login Successful\n";
		}
		else
		{
			cout<<"Error: Invalid Password"<<endl;
		}
	}
	else{
		cout<<"Error: Invalid Username or Password"<<endl;
	}
	
	// Close the file
	userFile.close();	
	
}

//Registration
void UserRegistration()
{
	ofstream userFile;
	char user[100];
	char pass[100];
	char filename[300]="";
	char fileLocation[5000] = "C:/Users/Moses/OneDrive/Documents/Mo Projects/CPP Projects/Login and Registration System/User Accounts/";
	char ext[10] = ".txt";
	cout<<"Registration Module\n\n";
	//User Enters ID
	cout<<"Enter Username: ";
	cin>>user;
	
	//User Enters Password
	cout<<"Enter Password: ";
	cin>>pass;
	
	strcat(filename,user); //username
	strcat(filename,ext); //username.txt
	strcat(fileLocation,filename); //assign filename and ext as file location
	//cout<<fileLocation<<endl;
	
	// Reads the text file
	userFile.open(fileLocation);
	userFile<<pass;
	
	// Close the file
	userFile.close();
	
	cout<<"Success: Account Created Successful\n";
}

//Modification
void UserModify()
{
	ofstream writeFile;
	ifstream readFile;
	char user[100];
	char pass[100];
	char newPass[100];
	char filename[300]="";
	char fileLocation[5000] = "C:/Users/Moses/OneDrive/Documents/Mo Projects/CPP Projects/Login and Registration System/User Accounts/";
	char ext[10] = ".txt";
	//char txt[100];
	string txt;
	cout<<"Modification Module\n\n";
	
	//User Enters ID
	cout<<"Enter Username: ";
	cin>>user;
	
	//User Enters Password
	cout<<"Enter Password: ";
	cin>>pass;
	
	strcat(filename,user); //username
	strcat(filename,ext); //username.txt
	strcat(fileLocation,filename); //assign filename and ext as file location
	//cout<<fileLocation<<endl;
	
	
	//Open an Read file
	readFile.open(fileLocation);
	if(readFile.good())
	{
		readFile>>txt;
		
		// Close the file
		readFile.close();
		//check if user pass is correct
		if(txt == pass)
		{
			cout<<"Success: Login Successful\n\n";
			
			//open the file and update the details
			cout<<"Enter New Password: ";
			cin>>newPass;
			
			writeFile.open(fileLocation);
			writeFile<<newPass;
			
			writeFile.close();
			cout<<"Success: Details Modified Successful\n\n";
		}
		else
		{
			cout<<"Error: Invalid Password"<<endl;
		}
	}
	else{
		cout<<"Error: Invalid Username or Password"<<endl;
	}
	
	
	
	
}
