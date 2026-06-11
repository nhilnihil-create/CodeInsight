//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstring>
#include<sstream>
#include <iomanip>

using namespace std;

typedef long long ll ;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vii;
const double pi = 2*acos(0) ;

#define pf		  	printf
#define sf			  scanf
#define pb(a)         push_back(a)
#define mp			make_pair
#define fi			 first
#define se			 second
#define for0(i,n)        for(int i=0;i<n;i++)
#define for1(i,n)        for(int i=1;i<=n;i++)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
#define lcm(a, b)     ((a)*((b)/gcd(a,b)))
#define sq(a)		   (a)*(a)
#define nw				"\n"
#define abs(x)		fabs(x)
#define pcase(z,x)    cout<<"Case "<<z<<": "<<x<<"\n"
int main()
{
	int i,n;
	ll s=0;
	cin>>n;
	vi a(n);
	for0(i,n){cin>>a[i]; s+=a[i];}
	sort(a.begin(),a.end());
	if(s%10==0){
		int ck=0;
		for(i=0 ; i<n ; i++){
			if(a[i]%10!=0){
				s -= a[i];
				ck=1;
				break;
				}
			}
		if(ck==0){cout<<0<<nw; return 0;}
		}
	cout<<s<<nw;
	return 0;
}