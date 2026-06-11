#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using P=pair<int, int>;
const ll INF=1LL<<60;
const ll MOD=1e9+7;

int main(){
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for(auto &x: a) cin >> x;
    ll res=INF;
    for(int bits=0; bits<(1<<N); bits++){
        vector<int> b=a;
        int prev_i=0, cnt=0;
        bool ok=true;
        ll sum=0;
        if((~bits)>>0 & 1) continue;
        for(int i=0; i<N; i++){
            if((bits>>i) & 1){
                cnt++;
                if(i == 0) continue;
                for(int j=prev_i+1; j<i; j++){
                    if(b[prev_i] < b[j]) ok=false;
                }
                sum+=max(0, b[prev_i]-b[i]+1);
                b[i]=max(b[i], b[prev_i]+1);
                prev_i=i;
            }
        }
        if(cnt >= K && ok){
            res=min(res, sum);
        }
    }
    cout << res << endl;
    return 0;
}