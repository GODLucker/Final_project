// Final_project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctime>
#include "account.h"
#include <iomanip>
#include <ctime>




int main()
{
	int id = 1;
	int menu;
	std::time_t t = std::time(NULL);
	std::tm tm = *std::localtime(&t);
	date date_create(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	std::vector<account> accountList;
	//FOR TEST 
	date credit_end(1, 4, 2021);
	date deposit_end;
	account client1(0, "credit account", "UAH", "Monobank", credit, 16, 3000,date_create, credit_end);
	account client2(1, "deposit account", "UAH", "Monobank", deposit, 16, 6000, date_create,credit_end);
	

	accountList.push_back(client1);
	accountList.push_back(client2);


	while (true)
	{
		cout << "-----------BANK ACCOUTN-----------\n";
		cout << "0 - Exit\n1 - Create account\n2 - Show avalibale card\n3 - Show info from avalible cards\n";
		cout << "4 - Save spending\n5 - Save replenishment\n6 - Check expenses and income from period \n";
		cin >> menu;
		switch (menu)
		{
		case 0:
		{
			cout << "See u\t\n";
			return 0;
			break;
		}
		case 1:
		{
			int  type_card, day, month, year;;
			float first_deposit, year_percent;
			string bank_currency, bank_name, account_name;
			date deposit_end(0,0,0);
			date credit_end(0,0,0);
			cout << "\tYou choose create account!\n";

			cout << "Enter account name: ";
			cin >> account_name;
			cout << "Enter avalible currency UAH,USD,EUR: \n";
			cin >> bank_currency;
			while(true)
			{ 
				if (bank_currency != "UAH" && bank_currency != "USD" && bank_currency != "EUR")
				{
					cout << "Only capital letters only!\n Example: Q W E R T..\n";
					cout << "Enter avalible currency UAH,USD,EUR: ";
					cin >> bank_currency;
					
				}
				else
					break;
			}
			cout << "Enter name of banking: " << endl;
			cin >> bank_name;
			cout << "Enter account card type\n ";
			cout << "(0-Current account,1-card account,2-deposit account,3-credit account,4-other account) : ";
			cin >> type_card;
			if (type_card == 2 )
			{
				cout << "Enter year precent: \n";
				cin >> year_percent;

				cout << "Enter of date deposit ending: ";
				cout << "Enter data: \nDay: ,Month: ,Year: \n";
				cin >> day >> month >> year;
				date deposit_end(day, month, year);
				cout << "Enter first ammount to deposit on your new account\n";
				cin >> first_deposit;
				
			}
			else if (type_card == 3)
			{
				cout << "Enter year precent: \n";
				cin >> year_percent;
				cout << "Enter of date credit ending: ";
				cout << "Enter data: \nDay: ,Month: ,Year: \n";
				cin >> day >> month >> year;
				date credit_end(day, month, year);
				cout << "Enter first ammount to deposit on your new account\n";
				cin >> first_deposit;
			}
			else
			{ 
			cout << "Enter first ammount to deposit on your new account\n";
			cin >> first_deposit;
			}
			while(true)
			{ 
			if (type_card != 2 && type_card != 3 && first_deposit >= 0)
			{

				account newaccount(id++, account_name, bank_currency, bank_name, cards_type(type_card),first_deposit);
				accountList.push_back(newaccount);
				break;
			}
			else if (type_card == 2 && first_deposit>=0)
			{
				account newaccount(id++, account_name, bank_currency, bank_name, cards_type(type_card), year_percent, first_deposit, date_create,deposit_end);
				accountList.push_back(newaccount);
				break;
			}
			else if (type_card == 3)
			{
				account newaccount(id++, account_name, bank_currency, bank_name, cards_type(type_card), year_percent, first_deposit, date_create, credit_end);
				accountList.push_back(newaccount);
				break;
			}
			else
				cout << "\n\tOnly credit account could have minus balance!\n";
			cout << "Enter first ammount to deposit on your new account\n";
			cin >> first_deposit;
			
			}
			break;


		}
		case 2:
		{
			cout << "You choose avalible card info: \n";

			for (const auto& account : accountList) {
				cout << "\nCard ID:" << account.get_id() << " " << account.show_cards_type(account.get_Card()) << endl;
			}
			break;

		}
		case 3://Spending money
		{
			cout << "You choose show info from your avalible cards: \n";
			for (const auto& accountlist : accountList)
			{
				cout << accountlist << endl;
			}
			break;
		}
		case 4:
		{
			int id, day, month, year;
			float spend_money;
			transaction_type::spending;
			cout << "Enter from what account minus spending: ";
			cout << "Your avalible account: \n";
			for (const auto& account : accountList)
			{
				cout << "\nCard ID:" << account.get_id() << " Type card: " << account.show_cards_type(account.get_Card()) << " Money: " << account.get_remainder() << endl;
			}
			cout << "Enter ID: ";
			cin >> id;
			for (auto i = 0; i < accountList.size(); i++)
			{
				if (accountList[i].get_id() == id)
				{
					cout << "Enter the sum of spending: ";
					cin >> spend_money;
					accountList[i].spending(spend_money);
					cout << "Enter data of spending: \nDay: ,Month: ,Year: \n";
					cin >> day >> month >> year;
					date date_tr(day, month, year);
					transaction tr(spend_money, spending, date_tr);
					accountList[i].get_tr().push_back(tr);
					break;
				}
				else
				{
					cout << "Do not have entered ID in list\nTry again!\n";
					break;
				}

			}
			break;
		}
		case 5:
		{
			cout << "You entered save replenishment!\n";
			int id, day, month, year;
			float replenishment_money;
			transaction_type::replenishment;
			cout << "Enter from what account plus replenishment. \n";
			cout << "Your avalible account: \n";
			for (const auto& account : accountList)
			{
				cout << "\nCard ID:" << account.get_id() << " Type card: " << account.show_cards_type(account.get_Card()) << " Money: " << account.get_remainder() << endl;
			}
			cin >> id;
			for (auto i = 0; i < accountList.size(); i++)
			{
				if (accountList[i].get_id() == id)
				{
					cout << "Enter the sum of replenishment: ";
					cin >> replenishment_money;
					accountList[i].income(replenishment_money);
					cout << "Enter data of spending: \nDay: ,Month: ,Year: \n";
					cin >> day >> month >> year;
					date date_tr(day, month, year);
					transaction tr(accountList[i].get_remainder(), replenishment, date_tr);
					accountList[i].get_tr().push_back(tr);
					break;
				}
				else
				{
					cout << "Do not have entered ID in list\nTry again!\n";
					break;
				}
			}
			break;
		}
		case 6:
		{
			int  day, month, year;

			cout << "You choose report about transaction.\n";
			cout << "Enter first date: \nDay,month.year: ";
			cin >> day >> month >> year;
			date first_date(day, month, year);
			cout << "Enter last date: \nDay,month.year: ";
			cin >> day >> month >> year;
			date last_date(day, month, year);
			for (auto i = 0; i < accountList.size(); i++)
			{
				vector<transaction> resList = accountList[i].get_tr_by_period(first_date, last_date);

				for (const auto& res : resList)
				{
					cout << res;
				}
			}
			break;
		}
		/*case 7:
		{
			int  day, month, year;

			cout << "You choose report about transaction.\n";
			cout << "Enter first date: \nDay,month.year: ";
			cin >> day >> month >> year;
			date first_date(day, month, year);
			cout << "Enter last date: \nDay,month.year: ";
			cin >> day >> month >> year;
			date last_date(day, month, year);

			vector<transaction> resList = client1.get_tr_by_period(first_date, last_date);

			for (const auto& res : resList)
			{
				cout << res;
			}

			break;
		}*/
		default:
		{
			cout << "Unknown command :(";
			break;
		}
		}

	}
	return 0;
}



