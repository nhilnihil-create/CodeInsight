//agc019_b.cpp
//Sat Jan  4 11:34:01 2020

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

int main(){
	string s;
	cin >> s;

	map<char, ll> mp;

	for (int i=0;i<s.length();i++){
		auto itr = mp.find(s[i]);
		if (itr != mp.end()){
			mp[s[i]]++;
		}else {
			mp[s[i]] = 1;
		}
	}

	ll ans = 0;
	for (auto itr = mp.begin();itr!=mp.end();itr++){
		ans+=(itr->second)*(itr->second-1)/2;
	}

	ll all = s.length()*(s.length()-1)/2+1;

	cout << all-ans<< endl;
//	printf("%.4f\n",ans);
}