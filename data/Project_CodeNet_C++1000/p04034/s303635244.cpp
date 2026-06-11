#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N, M;
    cin >> N >> M;
    int x, y;
    set<int> S;
    S.insert(1);
    vector<int> cnt(N+1, 1);
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        cnt[x]--;
        cnt[y]++;
        if(S.count(x)){
            S.insert(y);
            if(cnt[x] == 0){
                S.erase(x);
            }
        }
    }
    int ans = S.size();
    printf("%d\n", ans);

}