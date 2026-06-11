//arc069_d.cpp
//Sun Jan 12 18:18:40 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

char temp[100000];
int n;
string s;

bool check(char x, char y){
	fill(temp,temp+100000,'A');
	temp[0] = x;
	temp[1] = y;
	for (int i=1;i<n-1;i++){
		if (s[i]=='o'){
			if (temp[i]=='S'){
				temp[i+1] = temp[i-1];
			}else {
				if (temp[i-1]=='S'){
					temp[i+1] = 'W';
				}else {
					temp[i+1] = 'S';
				}
			}
		}else {
			if (temp[i]=='S'){
				if (temp[i-1]=='S'){
					temp[i+1] = 'W';
				}else {
					temp[i+1] = 'S';
				}
			}else {
				temp[i+1] = temp[i-1];
			}
		}
	}
	if (s[n-1]=='o'){
		if ((temp[n-1] == 'S' && temp[0]==temp[n-2]) ||
			(temp[n-1] == 'W' && temp[0]!=temp[n-2])){
			return true;
		}
	}else {
		if ((temp[n-1] == 'W' && temp[0]==temp[n-2]) ||
			(temp[n-1] == 'S' && temp[0]!=temp[n-2])){
			return true;
		}
	}
	return false;
}


int main(){
	cin >> n;
	cin >> s;

	bool test1 = check('S','S');
	if ((temp[n-1]=='S' && s[0] == 'o' && test1) ||
		(temp[n-1]=='W' && s[0] == 'x' && test1)){
		for (int i=0;i<n;i++){
			cout << temp[i];
		}
		printf("\n");
		return 0;
	}

	bool test2 = check('S','W');
	if ((temp[n-1]=='W' && s[0] == 'o' && test2) ||
		(temp[n-1]=='S' && s[0] == 'x' && test2)){
		for (int i=0;i<n;i++){
			cout << temp[i];
		}
		printf("\n");
		return 0;
	}

	bool test3 = check('W','S');
	if ((temp[n-1]=='W' && s[0] == 'o' && test3) ||
		(temp[n-1]=='S' && s[0] == 'x' && test3)){
		for (int i=0;i<n;i++){
			cout << temp[i];
		}
		printf("\n");
		return 0;
	}

	bool test4 = check('W','W');
	if ((temp[n-1]=='S' && s[0] == 'o' && test4) ||
		(temp[n-1]=='W' && s[0] == 'x' && test4)){
		for (int i=0;i<n;i++){
			cout << temp[i];
		}
		printf("\n");
		return 0;
	}
	cout << -1 << endl;
}