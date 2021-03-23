#include <iostream>
#include <list>
#include <iterator>
#include <string>

#define CAPACITY 50000 // Hash table size 

using namespace std;

// {key, value} struct

struct keyValue
{
	string key, value;
};

// Hash table class
class HashTable
{
public:
	list<keyValue>* table;
	int table_size;
	int table_count;

	HashTable();
	HashTable(int table_size);
	~HashTable();

	// Hash function
	int getHashKey(string& str);
	
	void insertItem(keyValue& item);

	void deleteItem(string key);

	void displayTable();
};

HashTable::HashTable()
{
	HashTable(CAPACITY);
}

HashTable::HashTable(int table_size)
{

	table = new list<keyValue>[table_size];
	this->table_size = table_size;
	this->table_count = 0;
}

HashTable::~HashTable()
{
	delete[] table;
}

int HashTable::getHashKey(string& str)
{
	return str.length();
}

void HashTable::insertItem(keyValue& item)
{
	int index = getHashKey(item.key);
	table[index].push_back(item);
}

void HashTable::deleteItem(string key)
{
	int index = getHashKey(key);
	list<keyValue> :: iterator i;

	for (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (i->key == key)
		{
			table[index].erase(i);
			break;
		}
	}

}


void HashTable::displayTable()
{
	for (int i = 0; i < table_size; i++) {
		cout << i;
		for (auto x : table[i])
		{
			cout << " --> key: " << x.key << " value: " << x.value; 
		}
			
		cout << endl;
	}
}



int main()
{
	cout << "Create hash table 1\n";

	HashTable hTable = HashTable(10);
	keyValue kv[5] = { 
		{"key1", "value3"},
		{"key12", "value21"},
		{"key14", "value152"},
		{"key1", "value1343"},
		{"k3", "value1111"},
	};

	for (auto kv_pair : kv)
	{
		hTable.insertItem(kv_pair);
	}

	hTable.displayTable();

	return 0;
}