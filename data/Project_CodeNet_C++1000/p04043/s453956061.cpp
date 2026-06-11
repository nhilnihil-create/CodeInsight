#include <bits/stdc++.h>

#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;

const int N = 1e5 + 12;
const ll mod = 1e9 + 7;

int n;

int main () {
	n = 3;
	map<int, int> mp;
	for(;n--;){
		int x;
		scanf("%d", &x);
		mp[x] += 1;
	}
	if(mp[5] == 2 && mp[7] == 1){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
}
