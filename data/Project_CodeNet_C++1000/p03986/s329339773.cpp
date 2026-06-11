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
    string s;
    cin>>s;
    int l=s.length();
    int sc=0;
    int tc=0;
    int mat=0;
    rep(i,l)
    {
        if(s[i]=='S')
        {
            sc++;
        }
        else
        {
            if(sc>0)
            {
                sc--;
                mat++;
            }
            
        }
        
    }
    cout<<l-2*mat;
}
