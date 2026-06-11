#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){
    
    ll H,W,h,w;cin>>H>>W>>h>>w;
    ll a=H/h,b=W/w;
    if(h*w==1) cout<<"No"<<endl;
    else{
        ll m=(1000000000-1)/(h*w-1);
        if(a*b*(-(h*w-1)*m-1)+(H*W-a*b)*m>0){
            cout<<"Yes"<<endl;
            for(ll i=1;i<=H;i++){
                for(ll j=1;j<=W;j++){
                    if(j>=2) cout<<" ";
                    if(i%h==0&&j%w==0) cout<<-(h*w-1)*m-1;
                    else cout<<m;
                }
                cout<<endl;
            }
        }else cout<<"No"<<endl;
    }
}

