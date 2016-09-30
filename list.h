#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
//Store heros names and description
struct list_of_heroes
{
	char * name_of_hero;
	char * description_of_hero;
};
//Store type of powers and situation powers are used
struct list_of_powers
{
	char * type_of_power;
	char * situation;
	list_of_heroes * heroes;
};
//Linked list
struct node
{
	list_of_powers data;
	int number_of_heroes;
	node * next;
};
//ADT class to store data 
class list
{
	public:
	list();
	~list();
 	//Function to build the list of powers
	//Will take 4 arguments from the client enterface
	int build_list(char power[], char situ[], char name[], char desc[]);
	//Function to display the list
	bool display_all(void);
	//Function to destroy the list
	bool remove_all(void);
	//Function to display a list of powers 
	bool display_powers_list(void);
	//Function to search the list for a power type
	node * search_for_power(char power[]);
	//Function to add a hero to a power node
	int add_hero_to_power(char name[], char desc[]);
	//Function to display a list of added heroes to the power
	void display_heroes(void);
	//Function to display specific power
	bool display_power(char power[]);
	//Function to remove a power node form the list
	bool remove_power(char power[]);
	//Function to display a power based on specific situation
	bool search_situation(char situ[]);

	private:
	node * head;
	node * search;
	int nodes_count;
};
