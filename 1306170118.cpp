#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<string>
using namespace std;
int x = 0;
vector < vector < string > > shoplist;
vector < string > product;
vector<string>::iterator rtr;
void menu();
void showlist();
void additem();
void creatmenu();
void edititem();
void deleteitem();
void checkundo();
void list();
void addlist();
void editlist();
void deletlist();
void undolist();
string converter(int x);
string converter(int x) {
	string element;
	stringstream out;
	out << x;
	element = out.str();
	return element;
}
void menu() {
	int number;
	cout << "    Main Menu" << endl;
	cout << "1.Create New Menu" << endl;
	cout << "2.Show Shopping List" << endl;
	cout << "0.Exit" << endl;
	cout << "input:";
	cin >> number;
	if (number == 1)
	{
		system("cls");
		creatmenu();
	}
	if (number == 2) {
		system("cls");
		showlist();

	}
	if (number == 0) {
		exit(number);
	}
}
void creatmenu() {
	int number;
	cout << "1.Add item" << endl;
	cout << "2.Edit item" << endl;
	cout << "3.Delete This List:" << endl;
	cout << "4.Mark as Done Undone" << endl;
	cout << "0.Previous Menu" << endl;
	cout << "input:";
	cin >> number;

	if (number == 1)
	{
		system("cls");
		additem();
	}

	if (number == 2)
	{
		system("cls");
		edititem();
	}

	if (number == 3)
	{
		system("cls");
		deleteitem();
	}

	if (number == 4)
	{
		system("cls");
		checkundo();
	}

	if (number == 0)
	{
		system("cls");
		shoplist.resize((0 + x));
		shoplist.insert((shoplist.begin() + x), product);
		x++;
		product.clear();
		menu();

	}
}
void additem() {
	string products, element;
	int amount;
	cout << "0.Previous Menu" << endl;
	while (true)
	{
		while (true)
		{
			cout << "Amount:";
			cin >> amount;
			if (amount != 0)
			{
				cout << "Product:";
				getline(cin, products);
				cin >> products;

				if (products != "0")
				{
					element = (converter(amount) + "  " + products);

					product.push_back(element);
				}
				else
				{
					system("cls");
					creatmenu(); break;
				}

			}
			else
			{
				system("cls");
				creatmenu(); break;
			}

		}
	}
	system("cls");
	creatmenu();
}
void edititem() {
	int num, amount;
	string element, e;
	//ptr = product.begin();
	cout << "----List---- " << endl;

	for (int i = 0; i < product.size(); i++)
	{
		cout << (i + 1) << "." << product[i] << endl;
	}cout << "0.Previous Menu" << endl;
	cout << "The line you want to change:";
	cin >> num;


	system("cls");

	if (num != 0) {
		cout << product[num - 1] << endl;
		cout << "Amount:";
		cin >> amount;
		if (amount != 0)
		{
			cout << "Product:";
			cin >> element;

			e = (converter(amount) + "  " + element);
			product[num - 1].swap(e);

		}

		//product.erase(product.begin() + num);

		cout << endl; edititem();

	}
	else {
		system("cls");
		creatmenu();
	}

	system("cls");
	creatmenu();
}
void deleteitem() {

	product.clear();
	system("cls");
	creatmenu();

}
void checkundo() {
	int num;
	string e = "(done)";
	string h;
	cout << "----List---- " << endl;
	for (int i = 0; i < product.size(); i++)
	{
		cout << (i + 1) << "." << product[i] << endl;
	}
	cout << "0.Previous Menu" << endl;
	cout << "Product To Be Marked:";
	cin >> num;


	system("cls");

	if (num != 0) {
		cout << product[num - 1] << endl;
		h = e + product[num - 1];

		product[num - 1].swap(h);
		//product.erase(product.begin() + num);

		cout << endl;
		system("cls");
		creatmenu();
	}
	else {
		system("cls");
		creatmenu();
	}

	system("cls");
	creatmenu();


}
void addlist() {
	string element, e;
	int listamount, amount;

	for (int i = 0; i < shoplist.size(); i++)
	{
		cout << (i + 1) << ". List" << endl;
	}
	cout << "0. Previous Menu" << endl;
	cout << "Choose a List:";
	cin >> listamount;

	if (listamount != 0)
	{

		for (int i = 0; i < shoplist[listamount - 1].size(); i++)
		{
			cout << (i + 1) << "." << shoplist[listamount - 1][i] << " " << endl;//liste  sýralama
		}
		system("cls");
		cout << "0.Previous Menu" << endl;
		cout << "Amount:";
		cin >> amount;

		if (amount != 0)
		{
			cout << "Product:";
			cin >> element;

			if (element != "0")
			{
				e = (converter(amount) + "  " + element);

				shoplist[listamount - 1].push_back(e);
			}
			else
			{
				system("cls");

				list();
			}
		}
		else
		{
			system("cls");

			list();
		}
	}

	else
	{
		system("cls");

		list();
	}

	system("cls");

	list();
}
void editlist() {
	string element, e;
	int listamount, amount;
	int edit;
	for (int i = 0; i < shoplist.size(); i++)
	{
		cout << (i + 1) << ". List" << endl;
	}cout << "0. Previous Menu" << endl;
	cout << "Choose a List:";
	cin >> listamount;

	//system("cls");
	if (listamount != 0)
	{
		for (int i = 0; i < shoplist[listamount - 1].size(); i++)
		{
			cout << (i + 1) << "." << shoplist[listamount - 1][i] << " " << endl;//liste sýralama

			cout << "0.Previous Menu" << endl;
			cout << "The line you want to change :";
			cin >> edit;
			if (edit != 0)
			{
				system("cls");
				cout << "Amount:";
				cin >> amount;
				system("cls");
				if (amount != 0)
				{
					cout << "Product:";
					cin >> element;

					if (element != "0")
					{
						e = (converter(amount) + "  " + element);

						shoplist[listamount - 1][edit - 1].swap(e);
						list();
					}
					else
					{
						system("cls");

						list();
					}
				}
				else
				{
					system("cls");

					list();
				}
			}

			else
			{
				system("cls");
				list();
			}
		}
	}

	else
	{
		system("cls");

		list();
	}

	system("cls");

	list();
}
void deletlist() {

	int listamount;
	for (int i = 0; i < shoplist.size(); i++)
	{
		cout << (i + 1) << ". List" << endl;
	}

	//cout << "No Previous Menu" << en
	cout << "0.Previous Menu" << endl;
	cout << "Select List to Delete:";
	cin >> listamount;

	if (listamount != 0)
	{
		cout << shoplist[listamount - 1].size() << endl;
		for (int i = 0; i < shoplist[listamount - 1].size(); i++)
		{
			cout << (i + 1) << "." << shoplist[listamount - 1][i] << " " << endl;
		}
		shoplist[listamount - 1].clear();
		shoplist[listamount - 1].push_back("Deleted");
		system("cls");
		list();
	}


	else
	{
		system("cls");
		list();
	}
	system("cls");
		list();
}
void undolist() {
	string e = "(done)";
	string element;
	int listamount;
	int edit;
	for (int i = 0; i < shoplist.size(); i++)
	{
		cout << (i + 1) << ".List" << endl;
	}

	cout << "0.Previous Menu" << endl;
	cout << "Choose a List:";

	cin >> listamount;



	system("cls");
	if (listamount != 0) {
		for (int i = 0; i < shoplist[listamount - 1].size(); i++)
		{
			cout << (i + 1) << "." << shoplist[listamount - 1][i] << " " << endl;//liste sýralama
		}
		cout << "The line you want to change : " ;
		cin >> edit;

		if (edit != 0) {
			element = e + shoplist[listamount - 1][edit - 1];
			shoplist[listamount - 1][edit - 1].swap(element);
			system("cls");

			list();

		}
		else
		{
			system("cls");

			list();
		}

	}


	else
	{
		system("cls");

		list();
	}

}
void list() {
	int number;
	cout << "1.Add Product to a List:" << endl;
	cout << "2.Edit List" << endl;
	cout << "3.Delete List" << endl;
	cout << "4.Mark as Done Undone" << endl;
	cout << "0.Previous Menu" << endl;
	cout << "input:";
	cin >> number;

	if (number == 1)
	{
		system("cls");
		addlist();
	}

	if (number == 2) {
		system("cls");
		editlist();
	}
	if (number == 3)
	{
		system("cls");
		deletlist();
	}
	if (number == 4)
	{
		system("cls");
		undolist();
	}

	if (number == 0) {
		system("cls");
		menu();
	}
}
void showlist() {
	cout << "----Lists----" << endl;

	for (int i = 0; i < shoplist.size(); i++)
	{
		cout << (i + 1) << ". liste" << endl;
		for (int j = 0; j < shoplist[i].size(); j++)
		{
			cout << (j + 1) << "." << shoplist[i][j] << endl;

		}
		cout << endl;
	}


	list();

}
int main() {
	menu();
}