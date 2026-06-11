#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll n,x=0,y=0;
    cin>>n;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        if(l1[i]%4==0)x++;
        else if(l1[i]%2==0)y++;
    }
    //if(x==1)x+=1;
    if(2*x+1+y-1>=n&&y>=2&&x!=0)cout<<"Yes";
    else if(2*x+1>=n&&x!=0)cout<<"Yes";
    else if(x==0&&y>=2&&y-1>=n-1)cout<<"Yes";
    else cout<<"No";

    return 0;
}
