//
//  main.cpp
//  code league
//
//  Created by TAlimul BAri SHresTho on 7/18/20.
//  Copyright © 2020 SHresTho. All rights reserved.
//

#include <iostream>

#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
#define ll                      long long
#define min3(a,b,c)             min(a,min(b,c))
#define max3(a,b,c)             max(a,max(b,c))
#define min4(a,b,c,d)           min(min(a,b),min(c,d))
#define max4(a,b,c,d)           max(max(a,b),max(c,d))
#define max5(a,b,c,d,e)         max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e)         min(min3(a,b,c),min(d,e))
#define LCM(a,b)                (a/__gcd(a,b))*b
#define GCD(a,b)                __gcd(a,b)
#define INPUT(x)                freopen(x,"r",stdin)
#define OUTPUT(x)               freopen (x,"w",stdout)
#define PI                      acos(-1.0)
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define joldi               ios_base::sync_with_stdio(0);cin.tie(NULL);

 
using namespace std;
int main(){
    joldi
    int t;
    cin>>t;
    int n=3*t;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        
    }
    sort(a,a+n);
    ll k=0;
    
    for(int j=n-2;j>=t;j=j-2)
    {
        k=k+a[j];
    }
    cout<<k<<endl;
    
    
}
