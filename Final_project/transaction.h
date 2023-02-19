#pragma once
#include "date.h"

enum transaction_type
{
	spending,
	replenishment
};

class transaction
{
private:
	float money;
	transaction_type type;
	date date_tr;

public:

	transaction();
	transaction(float money, transaction_type type, date date_tr);

	float get_money();
	transaction_type get_type();
	date get_date();
	string show_cards_type(const transaction_type type) const;
	friend ostream& operator<<(ostream& out, const transaction& transaction);

	
};

