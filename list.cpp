#include "list.h"
//constructor
list::list()
{
	head = NULL;
	search = NULL;
}
list::~list() //destructor
{
	remove_all();
}
//this function builds the list
int list::build_list(char power[], char situ[], char name[], char desc[])
{
	node * add = new node;
	add->data.type_of_power = new char[strlen(power) + 1];
	add->data.situation = new char[strlen(situ) + 1];
	add->data.heroes = new list_of_heroes[50];
	add->data.heroes[0].name_of_hero = new char[strlen(name) + 1];
	add->data.heroes[0].description_of_hero = new char[strlen(desc) +1];
	add->number_of_heroes = 1;
	strcpy(add->data.type_of_power, power);
	strcpy(add->data.situation, situ);
	strcpy(add->data.heroes[0].name_of_hero, name);
	strcpy(add->data.heroes[0].description_of_hero, desc);
	if (head == NULL)
	{
	head = add;
	head->next = NULL;
	}
	else
	{
	add->next = head;
	head = add;
	}
	nodes_count++;
	return nodes_count;
}

//Function to display the list
bool list::display_all(void)
{
	if (head == NULL)
	return false;

	node * curr = head;
	while (curr)
	{
	cout << "Type of super_power: " << curr->data.type_of_power
	<< "  This power can be used in: " << curr->data.situation << endl;
	for (int i = 0; i < curr->number_of_heroes; i++)
	{
	cout << "Hero using this super_power: " << curr->data.heroes[i].name_of_hero
	<< "  Heros' description: " << curr->data.heroes[i].description_of_hero << endl;
	}
	cout << endl;
	curr = curr->next;
	}
}

//Function to destroy the list
bool list::remove_all(void)
{
	if (!(head))
	return false;

	while (head)
	{
	node * pre = head;
	head = head->next;
	pre->next = NULL;
	for (int i = 0; i < pre->number_of_heroes; i++)
	{
	delete []pre->data.heroes[i].name_of_hero;
	delete []pre->data.heroes[i].description_of_hero;
	}
	delete []pre->data.heroes;
	delete []pre->data.type_of_power;
	delete []pre->data.situation;
	nodes_count--;
	delete pre;
	}
	return true;
}
        
//Function to display a list of powers
//for user to chosse power to add hero to         
bool list::display_powers_list(void)
{
	if (head == NULL)
	return false;

	node * curr = head;
	while (curr)
	{
	cout << "Type of super_power: " << curr->data.type_of_power;
	cout << endl;
	curr = curr->next;
	}
	
}
        
//Function to search the list for a power type
//Return pointer to node with desired power to add more heros
node * list::search_for_power(char power[])
{
	search = head;
	while (search)
	{
	if (strcmp(search->data.type_of_power, power) == 0)
	return search;
	}
	search = search->next;
}
        
//Function to add a hero to a power node
int list::add_hero_to_power(char name[], char desc[])
{
	node * curr = search;
	curr->data.heroes[curr->number_of_heroes].name_of_hero = new char[strlen(name) + 1];
	curr->data.heroes[curr->number_of_heroes].description_of_hero = new char[strlen(desc) + 1];
	strcpy(curr->data.heroes[curr->number_of_heroes].name_of_hero, name);
        strcpy(curr->data.heroes[curr->number_of_heroes].description_of_hero, desc);
	curr->number_of_heroes++;
	return curr->number_of_heroes;	
}
        
//Function to display a list of added heros to the power
void list::display_heroes(void)
{
	node * curr = search;
	cout << "Type of super_power: " << curr->data.type_of_power
	<< "  This power can be used in: " << curr->data.situation << endl;
	for (int i = 0; i < curr->number_of_heroes; i++)
	{
	cout << "Hero using this super_power: " << curr->data.heroes[i].name_of_hero
	<< "  Heros' description: " << curr->data.heroes[i].description_of_hero << endl;
	}
	cout << endl;
}
        
//Function to display specific power
bool list::display_power(char power[])
{
	node * curr = head;
	while (curr)
	{
	if (strcmp(curr->data.type_of_power, power) == 0)
	{
	cout << "Type of super_power: " << curr->data.type_of_power
        << "  This power can be used in: " << curr->data.situation << endl;
        for (int i = 0; i < curr->number_of_heroes; i++)
        {
        cout << "Hero using this super_power: " << curr->data.heroes[i].name_of_hero
        << "  Heros' description: " << curr->data.heroes[i].description_of_hero << endl;
	}
	return true;
	}
	}
	curr = curr->next;
	
	return false;
}
        
//Function to remove a power node form the list
bool list::remove_power(char power[])
{
	if (head->next == NULL)
	{
	list::remove_all();
	return false;
	}
	
	node * curr = head->next;
	node * pre = head;

	while(curr)
	{
	//second case: power in first node	
	if (strcmp(pre->data.type_of_power, power) == 0)
	{
	head = curr;
	pre->next = NULL;
	for (int i = 0; i < pre->number_of_heroes; i++)
        {
        delete []pre->data.heroes[i].name_of_hero;
        delete []pre->data.heroes[i].description_of_hero;
        }
        delete []pre->data.heroes;
        delete []pre->data.type_of_power;
        delete []pre->data.situation;
        nodes_count--;
        delete pre;
	return true;
        }
	
	//third case: power not in first node
	if (strcmp(curr->data.type_of_power, power) == 0)
	{
	pre->next = curr->next;
	curr->next = NULL;
        for (int i = 0; i < curr->number_of_heroes; i++)
        {
        delete []curr->data.heroes[i].name_of_hero;
        delete []curr->data.heroes[i].description_of_hero;
        }
        delete []curr->data.heroes;
        delete []curr->data.type_of_power;
        delete []curr->data.situation;
        nodes_count--;
        delete curr;
        return true;
	}
	}
	pre = curr;
	curr = curr->next;
}

//Function to display a power based on specific situation
bool list::search_situation(char situ[])
{
	node * curr = head;
	while (curr)
	{
	if (strcmp(curr->data.situation, situ) == 0)
	{
	cout << "Type of super_power: " << curr->data.type_of_power
        << "  This power can be used in: " << curr->data.situation << endl;
        for (int i = 0; i < curr->number_of_heroes; i++)
        {
        cout << "Hero using this super_power: " << curr->data.heroes[i].name_of_hero
        << "  Heros' description: " << curr->data.heroes[i].description_of_hero << endl;
        }
        return true;
        }
        }
        curr = curr->next;

	return false;
}


