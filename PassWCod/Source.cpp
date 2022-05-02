#include <iomanip>
#include <iostream> 
#include <cctype>
#include <string>
#include <cstdlib>


using namespace std;

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

//classes
class password
{
private:
	string initpass;    //initial passwork
	string secondpass;     //second passorw
	int uppercase;        //variable for upper case
	int lowercase;       //variable for lower case
	int digitcount;      //number of digits entered 
	int specialChar;     //validation of special characters

	void setPassword1();        //prompts and reads in the initial password entry from the user
	void validateRequirements();	 // validates the initial password entered meets the minimum requirements established
	void setPassword2();          //prompts the user to reenter the password and reads in the value entered ONLY when the initial password is valid
	void validateMatch();         //validates that both password entries match exactly
	void display();               // displays the result

	bool validated = 0;


public:

	password()
	{
		uppercase = 0;
		lowercase = 0;
		digitcount = 0;
		specialChar = 0;

	}

	void driver();




};

//define functions
void password::setPassword1()
{
	cout << "Update Your Password" << endl << endl;
	cout << "Password Requirements:"
		<< "\n- minimum of 8 characters"
		<< "\n- minimum of 2 uppercase characters(A - Z)"
		<< "\n- minimum of 2 lowercase characters(a - z)"
		<< "\n- minimum of 2 digits(0 - 9)"
		<< "\n- minimum of 2 special characters : !, @, $, %, &, _" << endl << endl;
	cout << "enter password here:  ";
	cin >> initpass;



}

void password::validateRequirements()
{
	int plength = initpass.length();         //is grabbing the "initpass" and writing it as "plenght"
	while (plength < 8)   //not long enough
	{
		cout << "Error, not long enough, try again: ";
		cin >> initpass;
		plength = initpass.length();
	}

	for (int i = 0; i < plength; i++)
	{
		char c = initpass[i];
		//counts lowercase characters (a - z)            
		if (c >= 'a' && c <= 'z')
			lowercase++;
		//counts uppercase characters (A - Z)            
		else if (c >= 'A' && c <= 'Z')
			uppercase++;
		//counts number of required digits            
		else if (c >= '0' && c <= '9')
			digitcount++;
		//count special characters            
		else if (c == '!' || c == '@' || c == '$' || c == '%' || c == '&' || c == '_')
			specialChar++;
	}
	cout << lowercase << " lowercase letters" << endl;
	cout << uppercase << " uppercase letters" << endl;
	cout << digitcount << " digits" << endl;
	cout << specialChar << " special characters" << endl << endl;

	if (!lowercase || lowercase < 2)
	{
		cout << "Error:  password does not meet minimum lowercase requirements, try again: ";
		cin >> initpass;
		plength = initpass.length();
		validated = 0;
	}
	else if (!uppercase || uppercase < 2)
	{
		cout << "Error:  password does not meet minimum upercase requirements, try again: ";
		cin >> initpass;
		plength = initpass.length();
		validated = 0;

	}
	else if (!digitcount || digitcount < 2)
	{
		cout << "Error:  password does not meet minimum digits requirements, try again: ";
		cin >> initpass;
		plength = initpass.length();
		validated = 0;
	}
	else if (!specialChar || specialChar < 2)
	{
		cout << "Error:  password does not meet minimum special charaters requirements, try again: ";
		cin >> initpass;
		plength = initpass.length();
		validated = 0;
	}
	else
	{
		cout << "Password meets minimum requirements." << endl << endl;
		validated = true;
	}
	uppercase = 0;          //sets values of "uppercase" and the rest back to thier original value after being modified,
	lowercase = 0;          //so that in "setPassword2" it display only the ammount of characters typed the second time, instead of adding both "setPassword2" and "validateRequirements" and siplaying the addition
	digitcount = 0;         // as well as making sure the code checks for the number of characters the second time
	specialChar = 0;         //otherwise it will count it as correct because it add the two characters already in "validateRequirements" to "setPassword2"
}

void password::setPassword2()
{

	cout << "Reeneter new password:  ";
	cin >> secondpass;
	int plength2 = secondpass.length();

	if (plength2 >= 8)
	{

		for (int i = 0; i < plength2; i++)
		{
			char c = secondpass[i];
			//counts lowercase characters (a - z)            
			if (c >= 'a' && c <= 'z')
				lowercase++;
			//counts uppercase characters (A - Z)            
			else if (c >= 'A' && c <= 'Z')
				uppercase++;
			//counts number of required digits            
			else if (c >= '0' && c <= '9')
				digitcount++;
			//count special characters            
			else if (c == '!' || c == '@' || c == '$' || c == '%' || c == '&' || c == '_')
				specialChar++;
		}
		cout << lowercase << " lowercase letters" << endl;
		cout << uppercase << " uppercase letters" << endl;
		cout << digitcount << " digits" << endl;
		cout << specialChar << " special characters" << endl << endl;

		if (!lowercase || lowercase < 2)
		{
			cout << "Error:  password does not meet minimum requirements, try again: ";
			cin >> secondpass;
			plength2 = secondpass.length();
		}
		else if (!uppercase || uppercase < 2)
		{
			cout << "Error:  password does not meet minimum requirements, try again: ";
			cin >> secondpass;
			plength2 = secondpass.length();

		}
		else if (!digitcount || digitcount < 2)
		{
			cout << "Error:  password does not meet minimum requirements, try again: ";
			cin >> secondpass;
			plength2 = secondpass.length();
		}
		else if (!specialChar || specialChar < 2)
		{
			cout << "Error:  password does not meet minimum requirements, try again: ";
			cin >> secondpass;
			plength2 = secondpass.length();
		}



	}
	while (plength2 < 8)
	{
		cout << "Error, not long enough, try again: ";
		cin >> secondpass;
		plength2 = secondpass.length();
	}




}
void password::validateMatch()
{
	cout << secondpass << "  " << initpass << endl << endl;
	while (secondpass != initpass)
	{

		cout << "Error:  update unsuccessful.  Entries do not match, try again:";
		cin >> secondpass;


	}

}

void password::display()
{
	if (secondpass == initpass)
	{

		cout << "\nPassword Update successful." << endl << endl << endl;
		cout << "Remember to change your password every 90 days." << endl << endl;
	}
}



void password::driver()      //this will call eveything else, write here to call
{
	setPassword1();
	while (validated == 0)   //while validated is false, not true
	{
		validateRequirements();
	}
	setPassword2();
	validateMatch();
	display();

}



//functions




int main()
{
	password p;
	p.driver();      //gonna call everything from "void password::driver()"



}