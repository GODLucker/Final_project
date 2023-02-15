// Final_project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "account.h"
int main()
{
	int id = 1;
	int menu;
	date credit_start(12, 1, 2021);
	date credit_end(1, 4, 2021);
	account client1(1, "credit_account", "USD", "Monobank", credit, 16, 3000, credit_end);
	std::vector<account> accountList;
	
	accountList.push_back(client1);
	
	
	while(true)
	{ 
		cout << "-----------BANK ACCOUTN-----------\n";
		cout << "0 - Exit,1 - Create account ,2-Show avalibale card  3 - Show info from avalible cards,4-Save spending,5-Save income,6 - Check expenses and income from period \n";
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
				int  type_account, type_card, year_percent, first_deposit;
				string bank_currency,bank_name,account_name;
		
				cout << "\tYou choose create account!\n";
				
				cout << "Enter account name: ";
				cin >> account_name;
				cout << "Enter avalible currency UAH,USD,EUR: \n";
				cin >> bank_currency;
				cout << "Enter name of banking: " << endl;
				cin >> bank_name;
				cout << "Enter account card type\n ";
				cout << "(0-Current account,1-card account,2-deposit account,3-credit account,4-other account) : ";
				cin>>type_card;
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
					cout << account.show_cards_type(account.getCard()) << endl;
				}
				break;
			
			}
			case 3:
			{
				cout << "You choose show info from your avalible cards: \n";
				for (const auto &accountlist : accountList)
				{
					cout << accountlist << endl;
				
				}
				break;
			}
			case 4:
			{
				int spend_money,day,month,year;
				transaction_type::spending;
				/*cout<<"Enter from what account minus spending: ";*/

				cout << "Enter the sum of spending: ";
				cin >> spend_money;
				client1.spending(spend_money);
				cout << "Enter data of spending: \nDay: ,Month: ,Year: \n";
				cin >> day >> month >> year;
				date date_tr(day, month, year);
				
				transaction trans(client1.get_remainder(), spending, date_tr);
				client1.getTrans().push_back(trans);
				break;

			}
			case 5:
			{

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
				vector<transaction> resList =  client1.get_tr_by_period(first_date, last_date);
				for (const auto& res : resList) {
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

