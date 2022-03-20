#include <iostream>
#include <set>
#include "DynamicString.h"
using namespace std;



int main()
{
	set<DynamicString, greater<DynamicString>> string_set;

	string_set.emplace(DynamicString("First message"));
	string_set.emplace(DynamicString("second message"));
	string_set.emplace(DynamicString("3 message"));
	string_set.emplace(DynamicString("fourth message"));
	string_set.emplace(DynamicString("fifth message"));


	for (auto i : string_set)
	{
		cout << i.get_array() << endl;
	}

	system("pause");
}