#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int n;
    cin>>n;


    if( n%2 )
    {
        stack<ll> odd ;
        queue<ll> even;
        for(int i=1 ;i<=n;i++)
        {
            ll temp;
            cin>>temp;
            if( i%2  ==0 )
            {
                even.push( temp);
            }
            else odd.push( temp);
        }
        while( !odd.empty())
        {
            cout<<odd.top()<<" ";
            odd.pop();
        }
        while (!even.empty() )
        {
            cout<<even.front()<<" ";
            even.pop();
        }
    } else
    {
        stack<ll> even;
        queue<ll> odd;
        for(int i=1 ;i<=n;i++)
        {
            ll temp;
            cin>>temp;
            if( i%2  ==0 )
            {
                even.push( temp);
            }
            else odd.push( temp);
        }
        while (!even.empty() )
        {
            cout<<even.top()<<" ";
            even.pop();
        }
        while( !odd.empty())
        {
            cout<<odd.front()<<" ";
            odd.pop();
        }
    }
}
