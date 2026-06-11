#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N; cin >> N;
    ll a[N],b[N];
    for(int i=0;i<N;i++){
        cin >> a[i] >> b[i];
    }
    reverse(b,b+N);
    reverse(a,a+N);
    ll ans=0;
    for(int i=0;i<N;i++){
        a[i]+=ans;
        ll tmp=(a[i]+(b[i]-1))/b[i];
        ans+=tmp*b[i]-a[i];
    }
    cout << ans << endl;
}