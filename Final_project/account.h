#pragma once
#include<iostream>
#include<string>
using namespace std;
enum cards_type
{
	current,// ��� ������� ������������ ��������
	card, //�볺����, �� ��������� �������� �� ������������� �������� ������
	deposit,
	credit,
	other
};
enum bank_account_name
{
	current_account,
	card_account,
	deposit_account,
	credit_account,
	other_account

};
class account
{
private:
	int id; //id
	bank_account_name name; //����� �������
	string currency; //������
	string bank_name; //����� �����
	cards_type type; //��� ������
	float additional_analytics;//�������, ���� ������������ �� �������
	float remainder;//�������
	string end_date;// �� ���� ������������ ���� ��������� �������� ��� �������.

public:
	account(int id, bank_account_name name, string currency, string bank_name, cards_type type, float additional_analytics, float remainder,string end_date);
	
	account(const account& other);
	account(const account&& other);
	account& operator=(const account& other);

	friend ostream& operator<<(ostream& out, account& name); //�������������� ��� ��'����
	friend ostream& operator<<(ostream& out, cards_type& type); //�������������� ��� ������� ���� ����
	

	int get_id();
	void set_id(int id);

	bank_account_name get_name();
	void set_name(bank_account_name name);

	string get_currency();
	void set_currency(string currency);

	string get_bank_name();
	void set_bank_name(string bank_name);

	cards_type get_type();
	void set_type(cards_type type);

	int get_additional_analytics();
	void set_additional_analytics(int additional_analytics);

	float get_remainder();
	void set_remainder(float remainder);

	string get_other();
	void set_other(string other);

	string show_cards_type(cards_type type);
	string show_bank_account_name(bank_account_name type);

	float spending(float spending_money);
	float income(float income_money);
	
	float simple_percent();
	float monthly_precent();

};

