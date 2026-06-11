#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

string c[]={"S", "W"};

int main(){
	int n;
	string s, t;
	cin >> n >> s;
	s+=s[0];
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			t=c[i]+c[j];
			for(int k=1; k<=n; k++)
			if(s[k]=='o'){
				if(t[k-1]==t[k]) t+='S';
				else t+='W';
			}else{
				if(t[k-1]==t[k]) t+='W';
				else t+='S';
			}
			if(t[0]==t[n] && t[1]==t[n+1]){
				cout << t.substr(0,n) << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}