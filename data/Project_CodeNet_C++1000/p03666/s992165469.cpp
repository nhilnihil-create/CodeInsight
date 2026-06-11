#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    ll N,A,B,C,D; cin>>N>>A>>B>>C>>D;
    ll diff=B-A;
    for (int i = 0; i <= N-1; ++i) {
        if(diff>=(N-1-i)*C-D*i&&diff<=(N-1-i)*D-C*i){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
