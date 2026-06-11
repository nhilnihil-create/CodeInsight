
// Problem : C - Lining Up
// Contest : AtCoder - AtCoder Beginner Contest 050
// URL : https://atcoder.jp/contests/abc050/tasks/arc066_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;

int MOD = 10e8+7; 

long long step(long long n){
    long long ans = 1;
    for(int i = 0; i < n; i ++){
        ans*=2;
        ans%=MOD;
    }
    return ans;
}

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, x;
	cin >> n;
	vector<int> f(n);
	for(int i = 0; i<n; i ++){
	    cin >> x;
	    f[x]++;
	}
	if(n&1){
	    for(int i = 0; i<n; i++){
	        if(i==0 && f[i]!=1 || i&1 && f[i]!=0 || (i&1==0 && f[i]!=2)){
	            cout << 0;
	            return 0;
	        }
	    }
	    cout << step(n/2);
	}
	else{
	   for(int i = 0; i<n; i++){
	        if(i&1==0 && f[i]!=0 || (i&1 && f[i]!=2)){
	            cout << 0;
	            return 0;
	        }
	    }
	    cout << step(n/2); 
	}
	return 0;
}