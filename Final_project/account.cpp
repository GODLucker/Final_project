#include "account.h"

account::account(int id, string name, string currency, string bank_name, cards_type type, float additional_analytics, float remainder, date end_date)
{
	
	this->id = id;
	this->name = name;
	this->currency = currency;
	this->bank_name = bank_name;
	this->type = type;
	this->additional_analytics = additional_analytics;
	this->remainder = remainder;
	this->end_date = end_date;
}

account::account(int id, string name, string currency, string bank_name, cards_type type, float remainder)
{
	this->id = id;
	this->name = name;
	this->currency = currency;
	this->bank_name = bank_name;
	this->type = type;
	this->remainder = remainder;
	
}


account::account(const account& other)
{
	id = other.id;
	currency = other.currency;
	name = other.name;
	bank_name = other.bank_name;
	type = other.type;
	additional_analytics = other.additional_analytics;
	remainder = other.remainder;
	end_date = other.end_date;
}

account::account(const account&& other)
{
	id = other.id;
	name = other.name;
	bank_name = other.bank_name;
	type = other.type;
	additional_analytics = other.additional_analytics;
	remainder = other.remainder;
	end_date = other.end_date;
}

account& account::operator=(const account& other)
{
	if (this == &other)
	{
		return *this;
	}
	id = other.id;
	currency = other.currency;
	name = other.name;
	bank_name = other.bank_name;
	type = other.type;
	additional_analytics = other.additional_analytics;
	remainder = other.remainder;
	end_date = other.end_date;
	return *this;
}



int account::get_id()const
{
	return id;
}

void account::set_id(int id)
{
	this -> id = id;
}

string account::get_name()
{
	return name;
}

void account::set_name(string name)
{
	this->name = name;
}

string account::get_currency()
{
	return currency;
}

void account::set_currency(string currency)
{
	this->currency = currency;
}

string account::get_bank_name()
{
	return bank_name;
}

void account::set_bank_name(string bank_name)
{
	this->bank_name = bank_name;
}

cards_type account::get_type()
{
	return type;
}

void account::set_type(cards_type type)
{
	this->type = type;
}

float account::get_additional_analytics()
{
	return additional_analytics;
}

void account::set_additional_analytics(float additional_analytics)
{
	this->additional_analytics = additional_analytics;
}

float account::get_remainder()const
{
	return remainder;
}

void account::set_remainder(float remainder)
{
	this->remainder = remainder;
}

date account::get_end_date()
{
	return end_date;
}

void account::set_end_date(date end_date)
{
	this->end_date = end_date;
}

float account::spending(float spending_money)
{
	
	return remainder = remainder - spending_money;

}

float account::income(float income_money)
{
	return remainder=remainder+income_money;
}

float account::simple_percent()const
{
	return ((remainder*additional_analytics*365)/365)/100;
}

//float account::monthly_precent()
//{
//	remainder=remainder * ((float (additional_analytics)/100) / 12);
//	return remainder;
//}

vector<transaction> account::get_tr_by_period(date start_p, date end_p)
{
	vector<transaction> result;

	for (int i = 0; i < all_transaction.size(); i++)
	{
		if (all_transaction[i].get_date() >= start_p && all_transaction[i].get_date() <= end_p)
		{
			result.push_back(all_transaction[i]);
		}
	}

	return result;
}


 string account::show_cards_type(const cards_type type) const 
{
	if (type == current)
	{
		return "current";
	}
	else if (type == card) {
		return "card";
	}
	else if (type == deposit) {
		return"deposit";
	}
	else if (type == credit) {
		return "credit";
	}

	return "other";

}
//string account::show_bank_account_name(bank_account_name type)
//{
//	if (current_account == type)
//	{
//		return "current_account";
//	}
//	else if (card_account== type)
//	{
//		return "card_account";
//	}
//	else if (deposit_account == type)
//	{
//		return "deposit_account";
//	}
//	else if (credit_account == type)
//	{
//		return "credit_account";
//	}
//	else if (other_account == type)
//	{
//		return "other_account";
//	}
//}
ostream& operator<<(ostream& out,const account& name)
{

	return out << "Id: " << name.id << " \nBank account name: " << name.name << " \nCurrency: " << name.currency << "\nBank name: "
		<< name.bank_name << "\nType card: " << name.show_cards_type(name.type) << "\nAnalytics: " << name.additional_analytics<<"%"<<" ~+"<<name.simple_percent()<<name.currency << "\nRemainder: " << name.remainder << "\nData of end credit or deposit: " << name.end_date << endl;
	
}

//ostream& operator<<(ostream& out,  cards_type& type)
//{
//	if (current == type)
//	{
//		out << "current" << endl;;
//	}
//	else if (card == type)
//	{
//		out << "card" << endl;
//	}
//	else if (deposit == type)
//	{
//		out << "deposit" << endl;
//	}
//	else if (credit == type)
//	{
//		out << "credit" << endl;
//	}
//	else if (other == type)
//	{
//		out << "other" << endl;
//	}
//	return (out);
//}


cards_type account::getCard() const  { return this->type; } 