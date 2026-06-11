#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    string s;
    cin >> s;
    ll n=s.size();
    //cout << n << "\n";
    ll point1;
    ll point2;
    ll flag=0;
    if(n==2)
    {
        if(s[0]==s[1])
        {
            flag=1;
            point1=0;
            point2=1;
        }
    }
    for(ll i=0;i<=n-2;i++)
    {
        //cout << s[i] <<"\n";
        if(i!=n-2)
        {

            if(s[i+1]==s[i] || s[i+2]==s[i] && flag==0)
            {
                flag=1;
                point1=i;
                point2=i+2;
            }
        }
        if(i==n-2)
        {
            if(s[i]==s[i+1] && flag==0)
            {
                point2=i+1;
                point1=i-1;
                flag=1;
            }
        }
    }
    //cout << flag<<"\n";
    if(flag==1)
    {

        cout << point1+1 <<" "<< point2+1;
    }
    else
    {
        cout <<"-1 -1";
    }
    /*for(ll j=point1;j<=point2;j++)
    {
        cout << s[j];
    }*/
}
