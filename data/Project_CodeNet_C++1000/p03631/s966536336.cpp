#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

     string a,b;
     cin>>a;
     b=a;
     int n= a.size();
     for(int i=0,j=n-1;i<n;++i,--j)
     {
         b[i]=a[j];
     }
     if(a==b){cout<<"Yes";}
     if (a!=b) {cout<<"No";}
}






