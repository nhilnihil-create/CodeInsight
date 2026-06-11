#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int manLength(int x1,int y1,int x2,int y2){
	return abs(x1-x2) + abs(y1-y2);
}
int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	int n = min(a.length(),b.length());
	for(int i = 0 ; i < 2*n; i++){
		if( i % 2 == 0){
			cout<<a[i/2];
		}else{
			cout<<b[i/2];
		}
	}
	if( a.length() > n){
		cout<<a[a.length()-1];
	}
	cout<<endl;
	return 0;
}

