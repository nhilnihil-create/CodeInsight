#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int ans=0;
	
	if(a==b && b==c){
		ans=1;
	}else if(a!=b && b!=c && c!=a){
		ans=3;
	}else{
		ans=2;
	}
	
	cout << ans << endl;
	
	return 0;
}
