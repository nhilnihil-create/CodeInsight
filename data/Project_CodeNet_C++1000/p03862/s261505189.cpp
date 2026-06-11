
// Problem : C - Boxes and Candies
// Contest : AtCoder - AtCoder Beginner Contest 048
// URL : https://atcoder.jp/contests/abc048/tasks/arc064_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, x, t = 0, c;
	cin >> n >> x;
	vector<int> v(n);
	for(auto &it:v) cin >> it;
	for(int i = 1; i < n; i++){
	    if(v[i-1]+v[i] > x){
	        c = v[i-1] + v[i] -x;
	        if(v[i]>c){
	            v[i]-=c;
	        }
	        else{
	            v[i] = 0;
	            v[i-1]-=c-v[i];
	        }
	        t+=c;
	    }
	}
	cout << t;
	return 0;
}