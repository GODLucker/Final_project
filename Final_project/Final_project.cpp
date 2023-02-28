// Final_project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctime>
#include "account.h"
#include <iomanip>
#include <ctime>
#include<conio.h>
#include <string>
#include<ctype.h>
#include <sstream>
#include<Windows.h>

bool get_date_from_input(date& date_obj);//прототип
bool isUnsignedNumber(const std::string& str);//прототип
template<class T>//зробили щоб не було проблеми з втратою даних(int,float)
bool isUnsignedNumber(T number); //прототип
bool date_checker(int day, int month, int year);//прототип
int main()
{
	int id = 1;
	int menu;
	std::time_t t = std::time(NULL);
	std::tm tm = *std::localtime(&t);
	date date_create(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	std::vector<account> accountList;
	//FOR TEST 
	//date credit_end(1, 4, 2021);
	//date deposit_end;
	//account client1(0, "credit account", "UAH", "Monobank", credit, 16, -3000,date_create, credit_end);//test
	//account client2(2, "deposit account", "UAH", "Monobank", deposit, 16, 6000, date_create,credit_end);//test
	//

	//accountList.push_back(client1);
	//accountList.push_back(client2);

	
	while (!_kbhit())
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
			int  type_card = 0, day = 0, month = 0, year = 0;;
			float first_deposit = 0, year_percent = 0;
			string bank_currency, bank_name, account_name;
			date deposit_end(0, 0, 0);
			date credit_end(0, 0, 0);
			cout << "\tYou choose create account!\n";

			cout << "Enter account name: ";
			cin >> account_name;
			cout << "Enter avalible currency UAH,USD,EUR: \n";
			cin >> bank_currency;
			while (true)
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
			if (type_card == 2)//сторюємо депозитну картку
			{
				cout << "Enter year precent: \n";

				cin >> year_percent;
				if (isUnsignedNumber(year_percent)) {}
				else { cout << "\nPercent could not be minus or plus or any symbols!\n"; break; }
				cout << "Enter of date deposit ending.\n";
				cout << "Enter data: \nDay: ,Month: ,Year: \n";
				cin >> day >> month >> year;
				if (date_checker(day, month, year) && isUnsignedNumber(day) && isUnsignedNumber(month) && isUnsignedNumber(year))// перевірка на коректність дати 
				{
					date deposit_end(day, month, year);
				}
				else { cout << "\nWrong date! Try again!\n"; break; }
				cout << "Enter first ammount to deposit on your new account\n";
				cin >> first_deposit;
				if (isUnsignedNumber(first_deposit)) {}
				else { cout << "\nFirst deposit could not be minus or any symbols!\n"; break; }
			}
			else if (type_card == 3) //сторюємо кредитну картку
			{
				cout << "Enter year precent: \n";
				cin >> year_percent;
				if (isUnsignedNumber(year_percent)) {}
				else { cout << "\nPercent could not be minus or plus or any symbols!\n"; break; }
				cout << "Enter of date credit ending: ";
				cout << "Enter data: \nDay: ,Month: ,Year: \n";
				cin >> day >> month >> year;
				if (date_checker(day, month, year) && isUnsignedNumber(day) && isUnsignedNumber(month) && isUnsignedNumber(year))// перевірка на коректність дати 
				{
					date credit_end(day, month, year);
				}
				else { cout << "\nWrong date! Try again!\n"; break; }

				cout << "Enter first ammount to deposit on your new account\n";
				cin >> first_deposit;
				if (isdigit(cin.peek()))
				{
				}
				else { cout << "\nFirst balance could not be a symbol! \n"; break; }
			}
			else
			{
				cout << "Enter first ammount to deposit on your new account\n";
				cin >> first_deposit;
			}
			while (true)
			{
				if (type_card != 2 && type_card != 3 && first_deposit >= 0)
				{

					account newaccount(id++, account_name, bank_currency, bank_name, cards_type(type_card), first_deposit);
					accountList.push_back(newaccount);
					break;
				}
				else if (type_card == 2 && first_deposit >= 0)
				{
					account newaccount(id++, account_name, bank_currency, bank_name, cards_type(type_card), year_percent, first_deposit, date_create, deposit_end);
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
				{
					cout << "\n\tOnly credit account could have minus balance!\n";
				}
				cin >> first_deposit;
				if (isdigit(cin.peek())) {}
				else { cout << "\nFirst balance could not be a symbol! \n"; break; }
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
		case 3:
		{
			cout << "You choose show info from your avalible cards: \n";
			for (const auto& accountlist : accountList)
			{
				cout << accountlist << endl;
			}
			break;
		}
		case 4://Spending money
		{
			cout << "You entered save spending!\n";
			int id, day, month, year;
			float spend_money;
			transaction_type trans_type = transaction_type::spending;

			cout << "Enter the ID of the account from which you want to make a payment: \n";
			cout << "Your available accounts: \n";
			for (const auto& account : accountList) {
				cout << "Card ID: " << account.get_id() << " Card Type: " << account.show_cards_type(account.get_Card()) << " Balance: " << account.get_remainder() << endl;
			}
			cout << "Enter the ID of the account: ";
			cin >> id;

			bool is_valid_id = false;
			for (auto i = 0; i < accountList.size(); i++) {
				if (accountList[i].get_id() == id) {
					is_valid_id = true;

					cout << "\nAttention, if you have a negative balance on a credit card, you will be charged 5% for each transaction!\n";
					cout << "Enter the amount of the payment: ";
					cin >> spend_money;
					accountList[i].spending(spend_money);
					cout << "Enter the date of the payment: \nDay: ,Month: ,Year: \n";
					cin >> day >> month >> year;

					if (date_checker(day, month, year) && isUnsignedNumber(day) && isUnsignedNumber(month) && isUnsignedNumber(year)) {
						date date_tr(day, month, year);
						transaction tr(spend_money, trans_type, date_tr);
						accountList[i].get_tr().push_back(tr);
					}
					else {
						cout << "\nInvalid date entered! Please try again.\n";
						break;
					}
					break;
				}
			}

			if (!is_valid_id) {
				cout << "The entered ID does not exist in the list. Please try again.\n";
				break;
			}
		}
		case 5://replenishment money
		{
			cout << "You entered save replenishment!\n";
			int id, day, month, year;
			float replenishment_money;
			transaction_type type = transaction_type::replenishment;

			cout << "Enter from what account to add funds. \n";
			cout << "Your available accounts: \n";

			for (const auto& account : accountList)
			{
				cout << "Card ID: " << account.get_id()
					<< " Type card: " << account.show_cards_type(account.get_Card())
					<< " Money: " << account.get_remainder() << endl;
			}

			cin >> id;

			bool found = false;

			for (auto& account : accountList)
			{
				if (account.get_id() == id)
				{
					cout << "Enter the amount of replenishment: ";
					cin >> replenishment_money;

					account.income(replenishment_money);

					cout << "Enter date of replenishment: \nDay: ,Month: ,Year: \n";
					cin >> day >> month >> year;

					if (date_checker(day, month, year) && isUnsignedNumber(day) && isUnsignedNumber(month) && isUnsignedNumber(year))
					{
						date date_tr(day, month, year);
						transaction tr(replenishment_money, type, date_tr);
						account.get_tr().push_back(tr);
						found = true;
						break;
					}
					else
					{
						cout << "\nWrong date! Try again!\n";
						break;
					}
				}
			}

			if (!found)
			{
				cout << "Entered ID is not in the list. Try again!\n";
			}

			break;
		}
		case 6:
		{
			cout << "You choose report about transaction.\n";
			date first_date, last_date;
			bool valid_first_date = get_date_from_input(first_date);
			if (!valid_first_date)
			{
				break;
			}
			bool valid_last_date = get_date_from_input(last_date);
			if (!valid_last_date)
			{
				break;
			}
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
		/*case 7://TEST CASE
		{
			int  day, month, year;
			
			cout << "You choose report about transaction.\n";
			cout << "Enter first date: \nDay,month.year: ";
			cin >> day >> month >> year;
				if (isUnsignedNumber(day) && isUnsignedNumber(month) && isUnsignedNumber(year))// Работает проверка на ввод только чисел по модулю
				{
			
				}else 
				{ 
				cout << "\nWrong date! Try again!\n";
				break; 
				}
			date first_date(day, month, year);
			cout << "Enter last date: \nDay,month.year: ";
			cin >> day >> month >> year;
				if(isUnsignedNumber(day)&& isUnsignedNumber(month)&& isUnsignedNumber(year))
				{ 
					if (date_checker(day, month, year))
					{
					}
					else { cout << "\nWrong date! Try again!\n"; break; }
					date last_date(day, month, year);
					vector<transaction> resList = client1.get_tr_by_period(first_date, last_date);

					for (const auto& res : resList)
					{
						cout << res;
					}
				}
				else 
				{ cout << "\nWrong date! Try again!\n"; break; }
			
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

bool date_checker(int day, int month, int year) {
	if (year < 1970) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	if (month == 2) {
		if (year % 4 == 0) {
			if (day < 1 || day > 29) {
				return false;
			}
		}
		else {
			if (day < 1 || day > 28) {
				return false;
			}
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day < 1 || day > 30) {
			return false;
		}
	}
	else {
		if (day < 1 || day > 31) {
			return false;
		}
	}
	return true;
}


bool isUnsignedNumber(const std::string& str) {
	// Проверяем, что введенная строка содержит только цифры и точки
	if (str.find_first_not_of("0123456789.") == std::string::npos) {
		try {
			// Пробуем преобразовать строку в число типа int
			int intNumber = std::stoi(str);
			return true;
		}
		catch (std::invalid_argument&) {
			try {
				// Если преобразование в int не удалось, пробуем преобразовать строку в число типа float
				float floatNumber = std::stof(str);
				return true;
			}
			catch (std::invalid_argument&) {
				return false;
			}
		}
	}
	else {
		return false;
	}
}
template<class T>//зробили щоб не було проблеми з втратою даних(int,float)
bool isUnsignedNumber(T number) {
	std::stringstream ss;
	ss << number;
	return isUnsignedNumber(ss.str());
}

bool get_date_from_input(date& date_obj)
{
	int day, month, year;
	cout << "Enter date (day, month, year): ";
	cin >> day >> month >> year;
	if (date_checker(day, month, year) && isUnsignedNumber(day) && isUnsignedNumber(month) && isUnsignedNumber(year))
	{
		date_obj = date(day, month, year);
		return true;
	}
	else
	{
		cout << "\nWrong date format. Please enter a valid date.\n";
		return false;
	}
}