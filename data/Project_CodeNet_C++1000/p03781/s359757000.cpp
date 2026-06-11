/*---------------------------*\
____________Mari000____________         
________Mostafa  Shehab________    
\*---------------------------*/

#include <bits/stdc++.h>
using namespace std;
 
#define PI  3.14159265  // PI = acos(-1)
#define EPS (1e-10)
#define endl "\n"
typedef long long ll;
typedef long double ld;
//template <class Type>

ll power(ll x,ll y,ll p);
int Bit(ll x);
 
inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}

const int N=1e5 + 5;
unordered_map<int,int> mp;
int n;
ll cnt=1e18,m;


int i;
int a,b,c,d,sum;

int main(){
	int n=D();
	for(i=1;sum<n;++i)
		sum+=i;
	--i;
	if(sum-n <= i)
		printf("%d",i);
	else
		printf("%d",i-1);

}










ll power(ll x,ll y,ll p){ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
    while (y > 0){ 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;
    }
    return res; 
}


int Bit(ll x){
	if(!x)
		return 0;
	return 1+Bit(x>>1);
}
















