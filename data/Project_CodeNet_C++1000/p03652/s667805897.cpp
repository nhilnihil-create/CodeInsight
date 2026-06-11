#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int> (M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> cnt(M+1);
    int m, ind;
    int ans;
    ans = inINF;
    for (int i = 0; i < M; i++) {
        fill(ALL(cnt), 0);
        for (int j = 0; j < N; j++) {
            cnt[a[j][0]]++;
        }
        m = 0;
        ind = 0;
        for (int j = 1; j <= M; j++) {
            if(cnt[j] > m){
                m = cnt[j];
                ind = j;
            }
        }
        ans = min(ans, m);

        for (int j = 0; j < N; j++) {
            a[j].erase(remove(ALL(a[j]), ind));
        }

    }
    printf("%d\n", ans);
    
}