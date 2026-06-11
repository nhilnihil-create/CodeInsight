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
typedef long long ll;

using namespace std;

int main(){
	string s;
	cin>>s;
	bool y=true;
	for(int i=0;i<(s.size()-1);i++){
		for(int j=i+1;j<s.size();j++){
			if(s[i]==s[j]){
				y=false;
				break;
			}
		}
		if(!y){
			break;
		}
	}
	if(y){
		cout<<"yes";
	}
	else{
		cout<<"no";
	}
}

