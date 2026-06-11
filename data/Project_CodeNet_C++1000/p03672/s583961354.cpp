#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
int n, m;

int main(){
	int i, j;
	string s;
	cin >> s;
	n = s.length();
	int ans=0, r=s.length()-2;
	for(i=n-2; i; i-=2){
		bool ok = 1;
		for(j=0;j<i/2;j++){
			if(s[j]!=s[j+i/2])ok=0;
		}if(ok){
			cout << i;
			return 0;
		}
	}return 0;
}
