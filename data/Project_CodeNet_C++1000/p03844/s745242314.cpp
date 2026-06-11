#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

#define ll long long

#define debug_message 0
#define debug if (debug_message)

#define sz(x) (int)x.size()

ll i,t,j;
ll n,m,nt,a,b;
string s,s1,s2;
char c;

int main(){
	scanf("%lld %c %lld",&a,&c,&b);
	
	if (c=='+') printf("%lld\n",a+b);
	else if (c=='-') printf("%lld\n",a-b);
	
	return 0;
}
/*

*/