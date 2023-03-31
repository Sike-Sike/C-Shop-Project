#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

float revenue = 0;
int item_no = 1000;

class item{
	char name[20];
	int number;
	float price;
	int inventory;

	public:
		item(char *itemname, int itemnumber, float itemprice, int iteminventory){
			strcpy(name, itemname);
			number = itemnumber;
			price = itemprice;
			inventory = iteminventory;
		}

		void itemdetails();
		void buyitem();
		void returnitem();
		void rename_item(char *iname);
		void update_price(float p);
		void add_inventory(int i);
		char* get_name();
};

void item::itemdetails(){
	cout<<"\nName : "<<name;
	cout<<"\nNumber : "<<number;
	cout<<"\nPrice : "<<price;
	cout<<"\nInventory : "<<inventory<<endl;
}

void item::buyitem(){
	inventory -= 1;
	revenue += price;
}

void item::returnitem(){
	inventory += 1;
	revenue -= price;
}

void item::rename_item(char *iname){
	strcpy(name, iname);
}

void item::update_price(float p){
	price = p;
}

void item::add_inventory(int i){
	inventory += i;
}

char* item::get_name(){
	return name;
}

vector<item> itm;

int chooseitem(){
	int ino;
	cout<<"\nEnter item number out of the following\n";
	for(int i = 0;i<itm.size();i++){
		cout<<i+1<<". "<<itm[i].get_name()<<endl;
	}
	cin>>ino;
	return ino-1;
}

int main(){
	int opt = 0, inventory = 0, flag = 1, ino;
	char name[20];
	float price;
	while(flag){
		cout<<"\nEnter Your Option";
		cout<<"\n1. Add item";
		cout<<"\n2. Remove item";
		cout<<"\n3. Buy item";
		cout<<"\n4. Return item";
		cout<<"\n5. Rename item";
		cout<<"\n6. Update price";
		cout<<"\n7. Add inventory";
		cout<<"\n8. Item details";
		cout<<"\n9. Display revenue";
		cout<<"\n10. Exit\n\n";
		cin>>opt;
		switch(opt){
			case 1:
				cout<<"\nEnter name of item\n";
				cin>>name;
				cout<<"\nEnter price of item\n";
				cin>>price;
				cout<<"\nEnter inventory of item\n";
				cin>>inventory;
				itm.push_back(item(name,item_no,price,inventory));
				item_no++;
				break;
			case 2:
				ino = chooseitem();
				if(ino >= itm.size()){
					cout<<"\nElement out of bounds\n";
					break;
				}
				itm.erase(itm.begin()+ino);
				break;
			case 3:
				ino = chooseitem();
				if(ino >= itm.size()){
					cout<<"\nElement out of bounds\n";
					break;
				}
				itm[ino].buyitem();
				break;
			case 4:
				ino = chooseitem();
				if(ino >= itm.size()){
					cout<<"\nElement out of bounds\n";
					break;
				}
				itm[ino].returnitem();
				break;
			case 5:
				ino = chooseitem();
				if(ino >= itm.size()){
					cout<<"\nElement out of bounds\n";
					break;
				}
				cout<<"\nEnter the new name of the item\n";
				cin>>name;
				itm[ino].rename_item(name);
				break;
			case 6:
				ino = chooseitem();
				if(ino >= itm.size()){
					cout<<"\nElement out of bounds\n";
					break;
				}
				cout<<"\nEnter the new price of the item\n";
				cin>>price;
				itm[ino].update_price(price);
				break;
			case 7:
				ino = chooseitem();
				if(ino >= itm.size()){
					cout<<"\nElement out of bounds\n";
					break;
				}
				cout<<"\nEnter the number of the item to be added\n";
				cin>>inventory;
				itm[ino].add_inventory(inventory);
				break;
			case 8:
				ino = chooseitem();
				if(ino >= itm.size()){
					cout<<"\nElement out of bounds\n";
					break;
				}
				itm[ino].itemdetails();
				break;
			case 9:
				cout<<"\nRevenue : "<<revenue<<endl;
				break;
			case 10:
				flag -= 1;
				break;
			default:
				cout<<"\nInvalid option\n";
		}
	}
	return 0;
}
