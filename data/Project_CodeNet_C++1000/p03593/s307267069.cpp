#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	int h, w;
	cin >> h >> w;
	queue<int> a;
	rep(i, h/2) rep(j, w/2) a.push(4);
	if(h%2 == 1 && w%2 == 0){
		rep(j, w/2) a.push(2);
	}else if(h%2 == 0 && w%2 == 1){
		rep(i, h/2) a.push(2);
	}else if(h%2 == 1 && w%2 == 1){
		rep(i, h/2) a.push(2);
		rep(j, w/2) a.push(2);
		a.push(1);
	}
	vector<int> al(26);
	rep(i, h){
		string s;
		cin >> s;
		rep(j, w) al[s.at(j) - 'a']++;
	}
	sort(al.begin(), al.end());
	queue<int> q;
	rep(i, 26) if(al[i] != 0) q.push(al[i]);
	bool f = true;
	int ll = 0;
	while(!q.empty()){
		int k = q.front();//85 10
		int t = a.front();//4 4 4 4 4 2 2 1
//		cout << k << ' ' << t << endl;
		int l = 0;
		while(k >= t){
			l = 1;
			k -= t;
			a.pop();
			if(a.empty()) break;
			t = a.front();
		}
		if(l == 0) ll++;
		else ll = 0;
		if(ll > 26*2+1){
			f = false;
			break;
		}
		if(k != 0) q.push(k);
		q.pop();
	}
	if(f){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}