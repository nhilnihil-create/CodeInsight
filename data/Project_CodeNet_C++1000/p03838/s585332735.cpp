#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    ll x,y; cin>>x>>y;
    ll ans=0;
    if(x<y){
        if(x>=0){
            ans=abs(y-x);
        }
        else{   //x<0
            if(y>0){   //y>=0>x
                ans=1+abs(y+x);
            }
            else if(y==0)ans=abs(x);
            else{   //0>y>x
                ans=abs(x-y);
            }
        }
    }
    else{   //x>y
        if(y>0){   //x>y>0
            ans=2+abs(x-y);
        }
        else if(y==0)ans=1+abs(x);
        else{   //y<0
            if(x>=0){   //x>0>y
                ans=1+abs(-x-y);
            }
            else{   //0>x>y
                ans=2+abs(abs(y)-abs(x));
            }
        }
    }
    cout<<ans;
    return 0;
}