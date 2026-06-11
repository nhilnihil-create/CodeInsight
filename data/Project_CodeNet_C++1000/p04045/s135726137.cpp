#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,d[10];
bool c[10];
int main(void){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>d[i];
        c[d[i]]=true;
    }
    while(true){
        ll m=n;
        bool x=true;
        while(m!=0){
            ll D=m%10;
            m=m/10;
            if(c[D]){
                x=false;
            }
        }
        if(x){
            cout<<n<<endl;
            return 0;
        }
        n++;
    }

}
