#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main() {
	int N;
	cin >> N;
	string s,t;
	cin >> s >> t;
	for(int i=0;i<s.size();i++){
		if(s.substr(i,s.size())==t.substr(0,t.size()-i)){
			string x = t.substr(t.size()-i,t.size());
			cout << s.size()+x.size() << endl;
			return 0;
		}
	}
	cout << s.size()+t.size() << endl;
	return 0;
}

