#include<iostream>
#include<string>
#include<vector>
#pragma once
using namespace std;

class Event
{
protected:
	pair<int, pair<int, int>>Date;
	string Description, Category, Place;
	vector<string>Members;
public:
	Event(){}
	Event(pair<int,pair<int,int>>d,string dd, string c, string p,vector<string>m):Date(d),Description(dd),Category(c),Place(p),Members(m){}
	Event(const Event&e):Date(e.Date),Description(e.Description),Category(e.Category),Place(e.Place),Members(e.Members){}

	~Event()
	{
		Members.clear();
	}

	friend istream& operator>>(istream& is, Event& e)
	{
		int day, month, year;
		is >> day >> month >> year;
		e.Date.first = day;
		e.Date.second.first = month;
		e.Date.second.second = year;
		is >> e.Description >> e.Category >> e.Place;
		size_t size = 0;
		is >> size;
		e.Members.resize(size);
		for (size_t i = 0; i < size; i++)
		{
			is >> e.Members[i];
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const Event& e)
	{
		os << e.Date.first << " " << e.Date.second.first << " " << e.Date.second.second << " " << e.Description << " " << e.Category << " " << e.Place << " "<<e.Members.size()<<" ";
		for (auto el : e.Members)
		{
			cout << el << " ";
		}
		return os;
	}

	pair<int, pair<int, int>> GetDate()
	{
		return Date;
	}

	string GetDescription()
	{
		return Description;
	}

	string GetCategory()
	{
		return Category;
	}

	string GetPlace()
	{
		return Place;
	}

	vector<string> GetMembers()
	{
		return Members;
	}

	void Print()
	{
		cout << "Date : " << Date.first << "." << Date.second.first << "." << Date.second.second << endl;
		cout << "Description : " << Description << endl;
		cout << "Category : " << Category << endl;
		cout << "Place : " << Place << endl;
		cout << "Members : ";
		for (auto el : Members)
		{
			cout << el << ",";
		}
	}
};

