///بِسْمِ الّٰلهِ الرَّحْمٰنِ الرَحِيْمِ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
     ios_base::sync_with_stdio(false);cin.tie(NULL);
     ll int i,n,t,j=0,p,x,a=0,b,l=0,r=0,y,k,c,sum=0,m,d;
     cin>>n>>k>>x>>y;
     if(k>n){
        p=n;
        l=0;
     }
     else{
        l=n-k;
        p=k;
     }
     cout<<p*x+l*y<<endl;


     return EXIT_SUCCESS;
}

