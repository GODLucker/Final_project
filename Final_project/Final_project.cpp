﻿// Final_project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<ctime>
#include "account.h"
int main()
{
	int id = 1;
	int menu;
	date credit_start(12, 1, 2021);
	date credit_end(1, 4, 2021);
	account client1(2, "credit account", "UAH", "Monobank", credit, 16, 3000, credit_end);
	account client2(1, "deposit account", "UAH", "Monobank", deposit, 16, 6000, credit_end);
	std::vector<account> accountList;

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
			int  type_card;
			float first_deposit, year_percent;
			string bank_currency, bank_name, account_name;

			cout << "\tYou choose create account!\n";

			cout << "Enter account name: ";
			cin >> account_name;
			cout << "Enter avalible currency UAH,USD,EUR: \n";
			cin >> bank_currency;
			cout << "Enter name of banking: " << endl;
			cin >> bank_name;
			cout << "Enter account card type\n ";
			cout << "(0-Current account,1-card account,2-deposit account,3-credit account,4-other account) : ";
			cin >> type_card;
			cout << "Enter year precent: \n";
			cin >> year_percent;
			cout << "Enter first ammount to deposit on your new account\n";
			cin >> first_deposit;
			account newaccount(id++, account_name, bank_currency, bank_name, cards_type(type_card), year_percent, first_deposit, credit_end);
			accountList.push_back(newaccount);

			break;


		}
		case 2:
		{
			cout << "You choose avalible card info: \n";

			for (const auto& account : accountList) {
				cout << "\nCard ID:" << account.get_id() << " " << account.show_cards_type(account.getCard()) << endl;
			}
			break;

		}
		case 3:
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
				cout << "\nCard ID:" << account.get_id() << " Type card: " << account.show_cards_type(account.getCard()) << " Money: " << account.get_remainder() << endl;
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
				/*else
				{
					cout << "Do not have entered ID in list\nTry again!\n";

				}*/

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
				cout << "\nCard ID:" << account.get_id() << " Type card: " << account.show_cards_type(account.getCard()) << " Money: " << account.get_remainder() << endl;
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
				/*else
				{
					cout << "Do not have entered ID in list\nTry again!\n";
				}*/
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
		case 7:
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
		}
		default:
		{
			cout << "Unknown command :(";
			break;
		}
		}

	}
	return 0;
}


