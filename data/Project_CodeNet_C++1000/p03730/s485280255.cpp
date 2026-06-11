#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fo(i,a,b) for(ll i=(a);i<=(b);++i)
#define fd(i,b,a) for(ll i=(b);i>=(a);--i)


int main(void){
    ll a,b,c;cin>>a>>b>>c;
    ll res=0;
    
    fo(i,1,b)
    {
        res=(res+a)%b;
        if(res==c)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}
