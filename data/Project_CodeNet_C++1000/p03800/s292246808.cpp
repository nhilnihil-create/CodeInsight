#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int n;
string s;
bool check(char a,char b,vector<char>& t){
	t[0] = a;
	t[1] = b;
	for(int i = 1;i < n-1;i++){
		if(s[i] == 'o'){
			if(t[i] == 'S')t[i+1] = t[i-1];
			if(t[i] == 'W')t[i+1] = (t[i-1] == 'S' ? 'W' : 'S');
		}
		if(s[i] == 'x'){
			if(t[i] == 'S')t[i+1] = (t[i-1] == 'S' ? 'W' : 'S');
			if(t[i] == 'W')t[i+1] = t[i-1];
		}
	}

	bool flag = true;
	for(int i = 0;i < n;i++){
		int prev = ((i - 1) + n) % n;
		int next = (i + 1) % n;
		if(s[i] == 'o'){
			if(t[i] == 'S'){
				if(t[prev] != t[next])return false;
			}
			if(t[i] == 'W'){
				if(t[prev] == t[next])return false;
			}
		}
		if(s[i] == 'x'){
			if(t[i] == 'S'){
				if(t[prev] == t[next])return false;
			}
			if(t[i] == 'W'){
				if(t[prev] != t[next])return false;
			}
		}
	}
	return true;
}


int main(){
	cin >> n;
	cin >> s;

	vector<char> t(n);
	if(check('S','W',t)){
		for(int i = 0;i < n;i++)cout << t[i];
		cout << endl;
		return 0;
	}
	if(check('S','S',t)){
		for(int i = 0;i < n;i++)cout << t[i];
		cout << endl;
		return 0;
	}
	if(check('W','S',t)){
		for(int i = 0;i < n;i++)cout << t[i];
		cout << endl;
		return 0;
	}
	if(check('W','W',t)){
		for(int i = 0;i < n;i++)cout << t[i];
		cout << endl;
		return 0;
	}

	cout << -1 << endl;
}
