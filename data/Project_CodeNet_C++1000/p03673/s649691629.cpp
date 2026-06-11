#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a;
ll b[300005];
bool k=false;
int main(void){
    cin>>n;
    for(int i=0;i<300005;i++){
        b[i]=-1;
    }
    for(int i=1;i<=n;i++){
        cin>>a;
        if(i%2==0){
            if(n%2==0){
                b[150000-i/2]=a;
            }else{
                b[150000+i/2]=a;
            }
        }else{
            if(n%2==0){
                b[150000+i/2]=a;
            }else{
                b[150000-i/2]=a;
            }
        }
    }
    for(int i=0;i<300005;i++){
        if(b[i]>=0){
            if(k) cout<<" ";
            cout<<b[i];
            k=true;
        }
    }
    cout<<endl;
    
}
