#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long

ll l1[100005];

int main()
{
    ll n,k;
    cin>>n>>k;
    ll a,b,y=0,x=0;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        x+=b;
        //if(x>=m&&y==0)y=a;
        l1[a]+=b;
    }
    for(int i=1;i<=100000;i++){
        if(k<=l1[i]){
            cout<<i<<endl;return 0;
        }
        k-=l1[i];
    }
}
