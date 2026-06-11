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
typedef long long ll;

int main()
{
	string str;
	cin>>str;
	vector<int> alphabet(26,0);
	for(int i = 0; i < str.length(); i++){
		int num = str[i] - 'a';
		alphabet[num]++;
	}
	bool ans = true;
	for(int i = 0; i < 26; i++){
		if( alphabet[i] % 2 != 0){
			ans = false;
			break;
		}
	}
	if( ans == true){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

