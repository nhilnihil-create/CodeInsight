//Bismillahir Rahmanir Rahim
//In the name of Allah the Most Merciful
//Astagfirullahil laji Rabbi Minkulli Jamio
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int i,j,k;
 main()
 {
     int n,k,x,y;
     cin>>n>>k>>x>>y;
     if(n<k) cout<<n*x<<endl;
     else cout<<k*x+(n-k)*y<<endl;
 }
