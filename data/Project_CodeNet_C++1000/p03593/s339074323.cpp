#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	map<char, int> m;
	rep(i, h){
		string s;
		cin >> s;
		rep(j, s.size()){
			m[s[j]]++;
		}
	}

	int x, y, z, v;
	if(h % 2 == 0){
		x = h/2;
		y = 0;
		v = 0;
	}else{
		x = h/2;
		y = w/2;
		v = 1;
	}
	if(w % 2 == 0){
		x *= (w/2);
		z = 0;
		v = 0;
	}else{
		x *= (w/2);
		z = h/2;
		v *= 1;
	}
	while(x > 0){
		pair<char, int> add(0, 0);
		for(auto p : m){
			if(add.second < p.second) add = p;
		}
		if(add.second < 4){
			cout << "No" << endl;
			return 0;
		}
		x--;
		m[add.first] -= 4;
	}
	while(y > 0){
		pair<char, int> add(0, 0);
		for(auto p : m){
			if(add.second < p.second) add = p;
		}
		if(add.second < 2){
			cout << "No" << endl;
			return 0;
		}
		y--;
		m[add.first] -= 2;
	}
	while(z > 0){
		pair<char, int> add(0, 0);
		for(auto p : m){
			if(add.second < p.second) add = p;
		}
		if(add.second < 2){
			cout << "No" << endl;
			return 0;
		}
		z--;
		m[add.first] -= 2;
	}
	while(v > 0){
		pair<char, int> add(0, 0);
		for(auto p : m){
			if(add.second < p.second) add = p;
		}
		if(add.second < 1){
			cout << "No" << endl;
			return 0;
		}
		v--;
		m[add.first] -= 1;
	}
	cout << "Yes" << endl;
	return 0;
}