#include<bits/stdc++.h>
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define ll long long int
using namespace std;
int main()
{
    ll tc;
    ll a,b,c,n,x,y,z,cnt=0,sum=0;
    string str;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        sum+=b-a+1;

    }
    cout<<sum<<endl;

}
