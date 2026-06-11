
// Problem : B - Comparison
// Contest : AtCoder - AtCoder Beginner Contest 059
// URL : https://atcoder.jp/contests/abc059/tasks/abc059_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a ,b;
	cin >> a >> b;
	int n1 = a.size(), n2 = b.size();
	if(n1>n2){
	    cout << "GREATER";
	}
	else if(n1<n2){
	    cout << "LESS";
	}
	else{
	    for(int i = 0; i < n1;i++){
	        if(a[i]>b[i]){
	            cout << "GREATER";
	            return 0;
	        }
	        else if(a[i]<b[i]){
	            cout << "LESS";
	            return 0;
	        }
	    }
	    cout << "EQUAL";
	}
	return 0;
}