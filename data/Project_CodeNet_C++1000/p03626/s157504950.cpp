#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100;

int main() {
	int n;cin>>n;
	string s,_;cin>>s>>_;
	long long ans;
	int i, last;
	if (s.size()==1) {cout<<3<<endl;return 0;}
	if (s[0]==s[1]) {ans=6;i=2;last=1;}
	else {ans=3;i=1;last=2;}
	for(;i<s.size();i++){
		if(i+1<s.size()) {
			if(last==1 && s[i]==s[i+1]) {ans=(ans*3)%MOD;i++;}
			else if(last==1 && s[i]!=s[i+1]) {last=2;}
			else if(last==2 && s[i]==s[i+1]) {ans=(ans*2)%MOD;i++;last=1;}
			else if(last==2 && s[i]!=s[i+1]) {ans=(ans*2)%MOD;}
		}
		else {
			if(last==2) ans=(ans*2)%MOD;
		}
	}
	cout<<ans<<endl;
}
