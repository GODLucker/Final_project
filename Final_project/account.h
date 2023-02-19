#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "transaction.h"
#include "date.h"
using namespace std;
 
  
enum cards_type
{
	current,// ��� ������� ������������ ��������
	card, //�볺����, �� ��������� �������� �� ������������� �������� ������
	deposit,
	credit,
	other
};
//enum bank_account_name
//{
//	current_account,
//	card_account,
//	deposit_account,
//	credit_account,
//	other_account
//
//};
class account
{
private:
	int id; //id
	string name; //����� �������
	string currency; //������
	string bank_name; //����� �����
	cards_type type; //��� ������
	float additional_analytics;//�������, ���� ������������ �� �������
	float remainder;//�������
	date end_date;// �� ���� ������������ ���� ��������� �������� ��� �������.
	vector<transaction> all_transaction; //�� ���������� �� �����

	
public:
	account(int id, string name, string currency, string bank_name, cards_type type, float additional_analytics, float remainder, date end_date);
	
	account(const account& other);
	account(const account&& other);
	account& operator=(const account& other);

	friend ostream& operator<<(ostream& out,const account& name); //�������������� ��� ��'����
	//friend ostream& operator<<(ostream& out, cards_type& type); //�������������� ��� �������(enum) ���� ����
	vector<transaction>& get_tr() {
		return all_transaction;
	}

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

	cards_type getCard() const;
	float get_additional_analytics();
	void set_additional_analytics(float additional_analytics);

	float get_remainder()const;
	void set_remainder(float remainder);

	date get_end_date();
	void set_end_date(date end_date);

	 string show_cards_type(const cards_type type) const;
	 /*string show_bank_account_name(string type);*/

	float spending(float spending_money);
	float income(float income_money);
	
	float simple_percent()const;
	float monthly_precent();


	vector<transaction> get_tr_by_period(date start_p, date end_p);

};
