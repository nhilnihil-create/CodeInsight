#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x,y;
    cin>>x>>y;
    if(x==2 || y==2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    vector<ll>a{1,3,5,7,8,10,12};
    vector<ll>b{4,6,9,11};
    if(binary_search(a.begin(),a.end(),x)==1)
    {
        if(binary_search(a.begin(),a.end(),y)==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        else
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    else
    {
        if(binary_search(b.begin(),b.end(),y)==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        else
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
}
