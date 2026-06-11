#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>
using namespace std;
string s,t;
vector<pair<int,int>> v;
string alp = "abcdefghijklmnopqrstuvwxyz";
set<int> st;
int solve(int l,int r){
	st.clear();
	for(int i=l;i<r;i++){
		st.insert(s[i]-'a');
	}
	for(int i=0;i<26;i++){
		if(!st.count(i)){
			return i;
		}
	}
}
int main(){
	cin >> s;
	int i,j,n = s.size(),l,r = n;
	for(i=n-1;i>=0;i--){
		st.insert(s[i]-'a');
		if(st.size()==26){
			l = i;
			v.push_back({l,r});
			r = i;
			st.clear();
		}
	}
	v.push_back({0,r});
	st.clear();
	l = 0;
	for(i=v.size()-1;i>=0;i--){
		r = v[i].second;
		int x = solve(l,r);
		t.push_back(alp[x]);
		for(j=r;j<n;j++){
			if(s[j]-'a'==x){
				l = j + 1;
				break;
			}
			if(j==n-1) l = n;
		}
	}
	cout << t << endl;
}