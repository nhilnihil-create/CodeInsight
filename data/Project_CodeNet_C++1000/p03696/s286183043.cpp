#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int open=0;
    int close=0;
    rep(i,n)
    {
        if(s[i]=='(' )
        {
            open++;
        }
        else
        {
            if(open==0)
            {
                close++;
            }
            else
            {
                open--;
            }
            
        }
        

    }
    if(close>0)
    {
        s=string(close,'(')+s;
    }
    if(open>0)
    {
        s+=string(open,')');
    }
    cout<<s;

}
