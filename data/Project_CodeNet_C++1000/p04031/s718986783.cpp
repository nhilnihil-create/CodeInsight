
// Problem : C - Be Together
// Contest : AtCoder - AtCoder Beginner Contest 043
// URL : https://atcoder.jp/contests/abc043/tasks/arc059_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, l1, r1, l2, r2, s= 0;
	int ans1 = 0, ans2=0, ans3=0, ans4=0;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
	    cin >> v[i];
	    s+=v[i];
	}
	l1 = s/n;
	r1 = l1+1;
	sort(v.begin(), v.end());
	if(n%2){
	    l2=v[n/2];
	    r2=l2+1;
	}
	else{
	    l2 = (v[n/2] + v[n/2-1])/2;
	    r2 = l2+1; 
	}
	for(int i:v){
	    ans1+=pow(l1-i,2);
	    ans2+=pow(r1-i,2);
	    ans3+=pow(l2-i,2);
	    ans4+=pow(r2-i,2);
	}
	cout << min(min(ans1,ans2), min(ans3,ans4));
	return 0;
}