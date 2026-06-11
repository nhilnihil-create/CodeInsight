#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    ll N,A,B; cin >> N >> A >> B;
    ll ans;
    if(N==1&&(A!=B)) ans=0;
    else if(A>B) ans=0;
    else ans=(N-1)*B+A-(N-1)*A-B+1;
    cout << ans << endl;
}