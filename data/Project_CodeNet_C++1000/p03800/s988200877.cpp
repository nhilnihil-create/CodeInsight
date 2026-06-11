#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
bool ok(char x,char y,char z,char w){
	int cnt = 0;
	if(y == 'S')cnt ++;
	if(w == 'o')cnt ++;
	if(cnt&1)return x != z;
	else return x == z;
}
string solve(string t){
	t.resize(n);
	for(int i = 1 ; i+1 < n ; i ++){
		int cnt = 0;
		if(s[i] == 'o')cnt ++;
		if(t[i] == 'S')cnt ++;
		if(cnt&1){
			if(t[i-1] == 'S')t[i+1] = 'W';
			else t[i+1] = 'S';
		}
		else t[i+1] = t[i-1];
	}
	//cout << t << endl;
	if(!ok(t[n-2],t[n-1],t[0],s[n-1]))return "";
	if(!ok(t[n-1],t[0],t[1],s[0]))return "";
	return t;
}
	

int main(){
	cin >> n >> s;
	string ret;
	string init[4] = { "SS","SW","WS","WW" };
	for(int i = 0 ; i < 4 ; i ++){
		ret = solve(init[i]);
		if(ret != ""){
			cout << ret << endl;
			return 0;
		}
	}
	puts("-1");
}

