#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,a[100005],b[100005];
ll mans,pans;
ll d;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i+1]=b[i]+a[i];
        //cout<<b[i+1]<<endl;
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            if(b[i]+d>=0){
                mans+=(b[i]+d+1);
                d-=(b[i]+d+1);
            }
        }else{
            if(b[i]+d<=0){
                mans+=(abs(b[i]+d)+1);
                d+=(abs(b[i]+d)+1);
            }
        }
        //cout<<i<<" "<<d<<" "<<mans<<endl;
    }
    d=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            if(b[i]+d<=0){
                pans+=(abs(b[i]+d)+1);
                d+=(abs(b[i]+d)+1);
            }
        }else{
            if(b[i]+d>=0){
                pans+=(b[i]+d+1);
                d-=(b[i]+d+1);
            }
        }
    }
    //cout<<pans<<" "<<mans<<endl;
    cout<<min(pans,mans)<<endl;

}
