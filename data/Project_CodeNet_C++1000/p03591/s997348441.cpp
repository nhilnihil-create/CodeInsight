//cod2017_qualA_a.cpp
//Sat Oct 20 22:33:34 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	string s;
	cin >> s;

	if (s.size()>=4 && 
		s[0] == 'Y' && 
		s[1] == 'A' && 
		s[2] == 'K' && 
		s[3] == 'I'){
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}

}