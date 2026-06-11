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
    int n,k;
    cin>>n>>k;
    vector<int> a(k);
    rep(i,k)cin>>a[i];
    while(1)
    {
    bool flag=true;
        int temp=n;
        while(temp>0)
        {
            bool inflag=true;
            int m=temp%10;
            temp/=10;
            for(auto v:a)
            {
                if(v==m)
                {
                    inflag=false;
                    break;
                }
            }
            if(!inflag)
            {
                flag=false;
                break;
            }
        }
        if(flag)break;
        n++;

    }
    cout<<n;
}
