#include <iostream>
#include <string>
#include <stdio.h>
#define llint long long

using namespace std;

string us = "999999999", ls = "1";

bool check(int n)
{
	char rep, rep2;
	cout << "? " << n << endl;
	cin >> rep;
	
	char tmp[20]; string s;
	sprintf(tmp, "%d", n);
	s = tmp;
	
	if(s >= us){
		if(rep == 'Y') return true;
		else return false;
	}
	if(s < ls){
		if(rep == 'N') return true;
		else return false;
	}
	
	string t = s;
	while(t.size() < 15) t += "0";
	cout << "? " << t << endl;
	cin >> rep2;
	
	if(rep2 == 'Y') us = s;
	else ls = t;
	
	if( (rep == 'Y') == (rep2 == 'Y') ) return true;
	else return false;
}

int main(void)
{
	int lb = 0, ub = 1000000005, mid;
	while(ub - lb > 1){
		mid = (lb + ub) / 2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << "! " << ub << endl;
	
	return 0;
}