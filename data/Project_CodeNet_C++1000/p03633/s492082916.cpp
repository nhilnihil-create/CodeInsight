#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll; 

ll findGCD(ll a, ll b){
    if(b==0)
          return a;
    return findGCD(b,a%b);
}

int main()
{
	int n;
	cin>>n;
	ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll lcm=a[0];
    for(int i=1;i<n;i++){
    	ll b;
    	b = findGCD(lcm,a[i]);
        lcm= lcm/b*a[i];
    }
    cout<<lcm;
}