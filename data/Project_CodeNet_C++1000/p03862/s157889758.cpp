#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    ll N,X;
    cin>>N>>X;
    vector<ll> a(N);
    for(int i=0; i<N; i++) cin>>a[i];

    ll ans  = 0;

    for(int i=1; i<N; i++){
        ll sum = a[i] + a[i-1];
        if(sum > X){
            ans += sum-X;
            if(sum-X > a[i]){
                a[i] = 0;
                a[i-1] -= sum-X-a[i];
            }else{
                a[i] -= sum-X;
            }
        }
    }

    cout<<ans<<endl;
}