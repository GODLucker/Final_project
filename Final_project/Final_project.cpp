// Final_project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "account.h"
int main()
{
	int menu;
	account client1(1, credit_account,"USD","Monobank",credit, 16,3000 ,"-");

	/*cout << "-----------BANK ACCOUTN-----------\n";
	cout << "0 - Exit, 1 - Show info, 2 - Check expenses, 3 - \n";
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
		cout << "You choose show info: \n";
		cout << client1;
		break;
	}
	case 2:
	{
		int spending_money;
		cout << "Current balance: " << client1.get_remainder() << endl;;
		cout << " Enter ammount of spending: ";
		cin >> spending_money;
		cout<<"New current balance: "<<client1.spending(spending_money);
		
	}
	}*/

	cout<<client1.monthly_precent();
	return 0;
}

