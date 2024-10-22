#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <json.hpp>
#include <sstream>

using namespace std;
using json = nlohmann::json;

// pair to link the value sorted by order 
typedef pair<long double, long double> values;
//map to sort the value got by the Fibonacci function
multimap<int, values> fibo;

void SaveToJson(multimap<int, values>::iterator list)
{
	json _value;
	fstream file;

	_value["x"][0] = list->first;

	for (list = fibo.begin(); list != fibo.end(); list++)
	{
		
		_value["x"][list->first] = list->second.first;
		_value["y"][list->first] = list->second.second;
		_value["a"][list->first] = list->second.second / list->second.first; //Binet formula
	}
	file.open(R"(..\data.json)", std::ios::out);
	
	file << _value.dump(2);
}

//This function iterate n times the fibonacci algorithm, store in the value map and then into the fibo map
void Fibo(int n)
{
	long double _l = 0;
	long double l = 1;
	long double nextTerm = 0;

	for (int i = 0; i < n; i++){
		nextTerm = _l + l;
		_l = l;
		l = nextTerm;
		fibo.insert(make_pair(i, make_pair(_l, l)));
		
		//for debug of precision
		//cout << i << " :" << setprecision(10e6) << nextTerm / _l << "\n";
	}
	for (multimap<int, values>::iterator it = fibo.begin(); it != fibo.end(); it++)
	{
		SaveToJson(it);
	}
}

int main()
{
	int num;
	cout << "nombre de termes : " << '\n';
	cin >> num;
	Fibo(num);

	return 0;
}
