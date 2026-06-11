#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<set>
#include <math.h>
#include <string>
#define cinf(n,x,y) for(int i=0;i<(n);i++) cin >> x[i]>>y[i];
typedef long long int ll;
using namespace std;

int main(){
	string s; cin >>s;
	string t="CODEFESTIVAL2016";
	int cnt=0;
	for(int i=0;i<16;i++){
		if(t[i]-s[i]!=0)cnt++;
	}
	cout << cnt << endl;
}