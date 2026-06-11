
// Problem : C - Sentou
// Contest : AtCoder - AtCoder Beginner Contest 060
// URL : https://atcoder.jp/contests/abc060/tasks/arc073_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, t, d;
	long long ans = 0ll;
	cin >> n;
	cin >> t;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
	    cin >> a[i];
	    if(i!=0){
	        d = a[i]-a[i-1];
	        if(d>=t){
	            ans+=t;
	        }
	        else{
	            ans+=d;
	        }
	    }
	}
	cout << ans+t;
	return 0;
}