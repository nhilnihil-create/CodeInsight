#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int count(int bit, int n){
    int cnt=0;
    REP(i, n){
        if(bit&1<<i) cnt++;
    }
    return cnt;
}

int main()
{
    int N,K;
    cin>>N>>K;

    vector<int> a(N); 
    REP(i, N) cin>>a[i];

    ll cost_min=INF;
    int bitsave=0;
    // 見える建物を仮定
    REP(bit, 1<<N){

        // 見える建物の個数と一致しない場合はスルー
        if(count(bit, N)!=K) continue;

        // 仮定した建物が見えるようにするコストを計算
        int maxnow=-1;
        ll cost = 0;
        REP(i, N){
            if(bit&1<<i){
                if(maxnow<a[i]){
                    maxnow=a[i];
                }
                else{
                    cost+=(maxnow+1-a[i]);
                    maxnow+=1;
                }
            }
            maxnow=max(maxnow, a[i]);
        }
        if(cost_min>cost){
            cost_min = cost;
            bitsave = bit;
        }
    }

    //cout << bitset<5>(bitsave) << endl;

    cout << cost_min << endl;

    return 0;
}