#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;


int main()
{
	string str;
	cin>>str;
	set<char> strSet;
	bool ans = true;
	for(int i = 0 ; i < str.length(); i++){
		if(strSet.count(str[i]) != 0){
			ans = false;
			break;
		}else{
			strSet.insert(str[i]);
		}
	}
	if(ans == true){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
	return 0;
}

