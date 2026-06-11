#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
long long INF = (1LL<<62);
typedef long long LL;
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

int maxd(string s, char c){
	int ret = 0, d = 0, found = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i] != c) d++;
		else{
			found = 1;
			if(ret < d) ret = d;
			d = 0;
		}
	}
	if(found == 0) return -1;
	if(ret < d) ret = d;
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s; cin >> s;
	int ans = 101;
	for(int i=0; i<26; i++){
		char c = alphabet[i];
		int d = maxd(s, c);
		if(d >= 0 && ans > d){
			ans = d;
		}
	}
	printf("%d\n", ans);
	return 0;
}
