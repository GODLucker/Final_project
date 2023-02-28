#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "transaction.h"
#include "date.h"
using namespace std;
 
  
enum cards_type
{
	current,// для ведення підприємницької діяльності
	card, //клієнтам, які здійснюють операції із застосуванням платіжних карток
	deposit,
	credit,
	other
};

class account
{
private:
	int id; //id
	string name; //назва рахунку
	string currency; //валюта
	string bank_name; //назва банку
	cards_type type; //тип картки
	float additional_analytics;//відсоток, який нараховується на залишок
	float remainder;//залишок
	date date_create;
	date end_date;// має бути прогнозована дата закінчення депозита або кредита.
	vector<transaction> all_transaction; //усі транзакції за період

	
public:
	account(int id, string name, string currency, string bank_name, cards_type type, float additional_analytics, float remainder, date date_create , date end_date);
	account(int id, string name, string currency, string bank_name, cards_type type,  float remainder);
	account(const account& other);
	account(const account&& other);
	account& operator=(const account& other);

	friend ostream& operator<<(ostream& out,const account& name); //перевантаження для об'єкту

	//friend ostream& operator<<(ostream& out, cards_type& type); //перевантаження для переліку(enum) типів карт
	vector<transaction>&get_tr();

	int get_id()const;
	void set_id(int id);

	string get_name();
	void set_name(string name);

	string get_currency();
	void set_currency(string currency);

	string get_bank_name();
	void set_bank_name(string bank_name);

	cards_type get_type();
	void set_type(cards_type type);

	cards_type get_Card() const;

	float get_additional_analytics();
	void set_additional_analytics(float additional_analytics);

	float get_remainder()const;
	void set_remainder(float remainder);

	date get_end_date()const;
	void set_end_date(date end_date);

	 string show_cards_type(const cards_type type) const;
	 /*string show_bank_account_name(string type);*/
	 
	float spending(float spending_money);
	float income(float income_money);
	
	float simple_percent(bool isLongYear)const;
	

	bool balance_checker();
	vector<transaction> get_tr_by_period(date start_p, date end_p);

};

 