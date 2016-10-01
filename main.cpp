//This reads in super hero and their powers along with descriptions and uses for the powers
//This also allows user input for everything already stated or to just add more heroes to powers.
//This program also allows searching, displaying, counting and deleting


#include "list.h"
#include <fstream>

//function to start over from the beginning
bool start_over(void);
//function to search the power you want to add heroes to. The argument is powers
void search_to_add(char power[]);
//function to ask if you want to add more powers
bool add_more_powers(void);
//function to add heroes and descriptions to exsisiting powers. The arguments are powers and heroes
void add_hero(char power_type[], char hero_name[]);
//function to add additional information other than what  was read in
//The arguments are power, situation where it is useful, hero and description
void get_data(char power_type[], char power_use[], char hero_name[], char hero_desc[]);
//function to ask if you want to add more heros to a power
bool would_hero(void);
//function to search for power that you want to add to. The argument is power
void search_add(char power_type[]);
//function to ask if you want to look for a situation that a power is useful
bool would_situation(void);
//function to ask if you want to delete a power
bool would_delete(void);
//function to ask what power to delete
void delete_power(char power);

//void search_situation(char power_use);

int main()
{
list test;     

char power_type[42];           //type of power
char power_use[42];		//situation where the power is useful
char hero_name[42];		//heroes name
char hero_desc[42];		//heroes description
//char power[42];		//Power to delete
int number_of_powers = 0;	//number of powers stored


ifstream inData_power;		//to input power and situation from external file
ifstream inData_hero;		//to input heroes and descriptions

do
{

	inData_power.open("power_list.txt");	
	inData_hero.open("hero_list.txt");

	while (!(inData_power.eof()))	//This is the part that all the files are read in 
	{
	inData_power >> power_type >> power_use;
	inData_hero >> hero_name >> hero_desc;
	number_of_powers = test.build_list(power_type, power_use, hero_name, hero_desc);
	} 

	inData_power.close();
	inData_hero.close();

	test.display_all();

	test.display_powers_list();
	cout << "Number of powers in the list: " << number_of_powers << endl;

	test.search_for_power(power_type);

test.remove_all();

if (add_more_powers() == true)
{					//this is to add more powers with heroes, uses, descriptions
	do
	{
	get_data(power_type, power_use, hero_name, hero_desc);
	test.build_list(power_type, power_use, hero_name, hero_desc);
	number_of_powers++;
	} while (add_more_powers() == true);
	
	cout << "Number of powers in the list: " << number_of_powers << endl;	
}

if(would_hero() == true)
{				//this is to add heroes to exsisting powers
	do
	{
	search_add(power_type);
	add_hero(hero_name, hero_desc);
	test.search_for_power(power_type);
	test.add_hero_to_power(hero_name, hero_desc);
	} while (would_hero() == true);
}
	
test.display_all();




} while(start_over() == true);

	
return 0;
}

bool start_over()
{
	char ans = 'Y';
	cout << "Would you like to start over? (y/n) \n";
	cin >> ans;
	cin.ignore(100, '\n');
	ans = toupper(ans);
	if (ans == 'Y')
	return true;

	return false;
}



void search_to_add(char power[])
{
	cout << "Please enter the power type you are adding hero to: \n";
	cin.get(power, 42, '\n');
	cin.ignore(100, '\n');
	power[0] = toupper(power[0]);
}

bool add_more_powers()
{
	char ans = 'Y';
	cout << "Would you like to add more powers? (y/n) \n";
	cin >> ans;
	cin.ignore(100, '\n');
	ans = toupper(ans);
	if (ans == 'Y')
	return true;

	return false;
}

void add_hero(char hero_name[], char hero_desc[])
{
	
	cout << "Please enter the hero name you wish to add: \n";
	cin.get(hero_name, 42, '\n');
	cin.ignore(100, '\n');
	cout << "Please enter the hero descreption: \n";
	cin.get(hero_desc, 42, '\n');
	cin.ignore(100, '\n');

}

void get_data(char power_type[], char power_use[], char hero_name[], char hero_desc[])
{
	cout << "What is the super hero's power? \n";
	cin.get(power_type, 42, '\n');
	cin.ignore(100, '\n');
	cout << "In what situation is this power useful? \n";
	cin.get(power_use, 42, '\n');
	cin.ignore(100, '\n');
	cout << "What is the super hero's name: \n";
	cin.get(hero_name, 42, '\n');
	cin.ignore(100, '\n');
	cout << "Can you describe the super hero? \n";
	cin.get(hero_desc, 42, '\n');
	cin.ignore(100, '\n');
}

bool would_hero()
{
	char ans = 'Y';
	cout << "Would you like to add a hero to a power? (y/n) \n";
	cin >> ans;
	cin.ignore(100, '\n');
	ans = toupper(ans);
	if (ans == 'Y')
	return true;

	return false;
}

void search_add(char power_type[])
{
	cout << "Please enter the power you are adding a super hero to: \n";
	cin.get(power_type, 42, '\n');
	cin.ignore(100, '\n');
}
