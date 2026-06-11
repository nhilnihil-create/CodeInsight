//#include<bits/stdc++.h>
#include<iostream>
//#include<vector>
//#include<map>
//#include <iomanip>
//#include<cstring>
//#include<string>
//#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
#define eps 1e-9
#define endl "\n"
#define PI acos(-1)
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(j,n) for(int j=0;j<n;j++)
using namespace std;
/*
ll mod=1e9+7;
bool f(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.first<b.first);
}
bool f2(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
} */

int main()
{
    fast;
    string a,b;
    cin>>a>>b;
    int al=a.length();
    int bl=b.length();
    if(al>bl)
    {
        cout<<"GREATER"<<endl;
    }
    else if(al<bl)
    {
        cout<<"LESS"<<endl;
    }
    else
    { //length equal
        int g=0,l=0,e=0;
        for(int i=0;i<al;i++)
        {
            if(a[i]>b[i])
            {
                g=1;
                e=1;
                break;
            }
            else if(a[i]<b[i])
            {
                l=1;
                e=1;
                break;
            }

        }
        if(e==0)
        {
            cout<<"EQUAL"<<endl;
        }
        else if(e==1&&g==1)
        {
            cout<<"GREATER"<<endl;
        }
        else
        {
            cout<<"LESS"<<endl;
        }



    }

    return 0;
}
