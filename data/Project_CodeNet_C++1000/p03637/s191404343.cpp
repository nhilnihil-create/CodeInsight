#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,x;
    string s;
    cin>>n;
    ll c4=0,ce=0,co=0;
    while(n--)
    {
        cin>>x;
        if(x%4==0) c4++;
        else if(x%2==0) ce++;
        else co++;
        
    }
    if(c4>=co)
    cout<<"Yes"<<endl;
    else if(co==c4+1&&ce==0)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    
   
   
   
   
   
    return 0;
}



