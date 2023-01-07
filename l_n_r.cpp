#include <iostream> 
#include <fstream> //because file handling
		   //omg comments are automatic in VIM!!!
		   //this is amazing
#include <cstring>
using namespace std;
//this below is for verifying are you creating an account or not
//so here we use bool value that always returns true or false
//if you have an account return true otherwise return false

bool isloggedin()
{
string username, password, un, pw; //un and pw are comparison strings

cout<<"Enter username :";
cin>>username;
cout<<"Enter password :";
cin>>password;

//reading a file that tells us if you have an account
ifstream read("data\\" + username + ".txt"); // data.txt is where our data 
					     // will save
getline(read, un); // for reading the user name 
getline(read, pw); // for reading the password

//comparison
cout<<"comparing input to our records\n"; 
cout<<"Username found is: "<<un<<endl;

if(un == username && pw == password)
{
return true;
}
else
{
return false;
}
}

int main()
{
	// system("colour 3f"); for color output in console
	int choice; 
	
	cout<<"1: Register \n2: Login\nYour choice :";
	cin>>choice;

	if(choice == 1){
	string username, password;
	cout<<"select a username :";
	cin>>username;
	cout<<"select a password :";
	cin>>password;

	ofstream file;
	file.open("data\\" + username + ".txt");
	//rewrite in the file
	file<<username<<endl<<password;
	file.close();

	//return here main because then again we are going to log in
	//then we register another user so: 
	main();
	}
	else if(choice == 2)
	{
	// create a variable status and assign into is logged in function
	// and then proceed
	bool status = isloggedin();

	if(!status) //if login goes wrong and/or password is incorrect
	{
	cout<<"Invalid username or password :"<<endl;
	//system("PAUSE");
		return 0; 
	}
	else // if successful login return 1 or proceed further
	{
	cout<<"Login Successful"<<endl;
	return 1;
	}
	} 
}
