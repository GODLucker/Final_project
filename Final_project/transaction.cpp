#include "transaction.h"

transaction::transaction()
{
	money = 0;
	type = transaction_type::replenishment;
	date_tr = date();
}

transaction::transaction(float money, transaction_type type, date date_tr)
{
	this->money = money;
	this->type = type;
	this->date_tr = date_tr;
}

float transaction::get_money()
{
	return money;
}

transaction_type transaction::get_type()
{
	return type;
}

date transaction::get_date()
{
	return date_tr;
}

ostream& operator<<(ostream& out, const transaction& tr)
{
	return out << "\nMoney: " << tr.money << " type: " << tr.type << " \nData_tr: " << tr.date_tr << endl;
}
