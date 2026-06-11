#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){	
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt_a=0;
	int cnt_b=0;
	vector<int> v(s.size(),0);
	for(int i=0;i<s.size();i++){
		if(s[i]=='(')cnt_b++;
		else cnt_a++;
		v[i]=cnt_a-cnt_b;
	}
	vector<int> x(v.size(),0);
	cnt_a=cnt_b=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]==')')cnt_b++;
		else cnt_a++;
		x[i]=cnt_a-cnt_b;
	}
	string t;
	int mx=*max_element(v.begin(),v.end());
	for(int i=0;i<mx;i++){
		t+='(';
	}
	s=t+s;
	mx=*max_element(x.begin(),x.end());
	for(int i=0;i<mx;i++){
		s+=')';
	}
	cout << s << endl;	
	return 0;
}
