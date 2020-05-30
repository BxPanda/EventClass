#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
#include"Event.h"

using namespace std;

void Print(vector<Event>& v)
{
	for (auto el : v)
	{
		el.Print();
		cout << endl << "------------------------------------------------------------------------" << endl;
	}
}

bool comp1(Event f, Event s)
{
	if (f.GetDate().second.second != s.GetDate().second.second)
	{
		return f.GetDate().second.second < s.GetDate().second.second;
	}
	else
	{
		if (f.GetDate().second.first!=s.GetDate().second.first)
		{
			return f.GetDate().second.first < s.GetDate().second.first;
		}
		else
		{
			if (f.GetDate().first!=s.GetDate().first)
			{
				return f.GetDate().first < s.GetDate().first;
			}
			else
			{
				if (f.GetPlace() != s.GetPlace())
				{
					return f.GetPlace() < s.GetPlace();
				}
				else
				{
					return f.GetCategory() < s.GetCategory();
				}
			}
		}
	}
}

void Sort(vector<Event>& v)
{
	sort(v.begin(), v.end(), comp1);
	cout << "Sorted : " << endl << endl;
	Print(v);
}

void EventCategory(vector<Event>& v)
{
	set<string>categories;
	for (auto el : v)
	{
		categories.insert(el.GetCategory());
	}
	int first, second;
	cout << "Input the time period in year , first  : " << endl;
	cin >> first;

	cout << "Input the time period in year , second  : " << endl;
	cin >> second;
	
	vector<Event>events;
	for (auto el : categories)
	{
		copy_if(v.begin(), v.end(), back_inserter(events), [&el,&first,&second](Event& e) 
		{
				if (e.GetDate().second.second >= first && e.GetDate().second.second <= second)
				{
					return el == e.GetCategory();
				}
				else
				{
					return false;
				}
		});
		cout << "Events " << el << " category : " << endl << endl;
		Print(events);
		events.clear();
	}
}

void RatingOnPlace(vector<Event>& v)
{
	set<string>people;
	for (auto el : v)
	{
		auto members = el.GetMembers();
		for (auto el : members)
		{
			people.insert(el);
		}
	}
	string place;
	cout << "Input place : ";
	cin >> place;
	for (auto el : people)
	{
		int count = 0;
		for (auto ell : v)
		{
			if (place == ell.GetPlace())
			{
				auto tmp = ell.GetMembers();
				auto it = find(tmp.begin(), tmp.end(), el);
				if (it != tmp.end())
				{
					count++;
				}
			}
		}
		cout << el << "'s rating in the events : " << count << endl;
	}
}

int main()
{
	ifstream ifs("Text.txt");
	ifstream ifs1("Text1.txt");

	vector<Event>v1;
	copy(istream_iterator<Event>(ifs), istream_iterator<Event>(), back_inserter(v1));
	copy(istream_iterator<Event>(ifs1), istream_iterator<Event>(), back_inserter(v1));

	Print(v1);

	Sort(v1);

	EventCategory(v1);

	RatingOnPlace(v1);
	return 0;
}