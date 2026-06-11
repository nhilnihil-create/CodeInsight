#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    REP(i, N){
        cin >> T[i];
    }
    
    sort(T.begin(), T.end());

    int ans = 1;
    int num = 1;
    int starttime = T[0];
    
    for (int i = 1; i < N; i++){
        if (T[i] <= K + starttime){
            if (num < C){
                num++;
            }
            else {
                num = 1;
                ans++;
                starttime = T[i];
            }            
        }
        else{
            ans++;
            num = 1;
            starttime = T[i];
        }
    }

    cout << ans << endl;
}