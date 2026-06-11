#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#define long long

using namespace std;

int main() {
	int a[26]={0};
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]-'a']++;
	}
	bool y=true;
	for(int i=0;i<26;i++){
		if(a[i]%2!=0){
			y=false;
		}
	}
	if(y){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}
