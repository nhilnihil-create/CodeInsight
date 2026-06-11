#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	string s;
	cin >> s;
	queue<int> a;
	stack<int> z;
	rep(i, s.size()){
		if(s[i] == 'A') a.push(i);
		else if(s[i] == 'Z') z.push(i);
	}

	cout << z.top() - a.front() + 1 << endl;
	return 0;
}