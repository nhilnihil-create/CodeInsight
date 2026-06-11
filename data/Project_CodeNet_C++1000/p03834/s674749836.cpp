#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

string s;
int main()
{

    cin>>s;
    rep(i,0,s.length()-1)
    {
        if(s[i]!=',')
            cout<<s[i];
        else
            cout<<" ";
    }
}


