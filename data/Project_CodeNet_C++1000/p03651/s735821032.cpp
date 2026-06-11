#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 1
#define INF (1LL<<50)
 
int gcd(lli x,lli y)
{
        if (y == 0) {
                return x;
        } else {
                return gcd(y, x % y);
        }
}
 
signed main(){
 
	lli n,k;
	cin>>n>>k;
	vector<lli> a(n);
	lli maxA=0;
	REP(i,0,n){
		cin>>a[i];
		maxA = max(maxA,a[i]);
	}
 
	lli num = gcd(max(a[0],a[1]),min(a[0],a[1]));
	REP(i,2,n)num = gcd(max(num,a[i]),min(num,a[i]));
 
	if(k>maxA){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else if(k%num==0){
		cout<<"POSSIBLE"<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
 
	return 0;
}