#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N, ma, mb;
    cin >> N >> ma >> mb;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    if(N == 1){
        if(b[0] * ma - a[0] * mb != 0){
            printf("%d\n", -1);
            return 0;
        }
        printf("%d\n", c[0]);
        return 0;
    }

    vector<iint> F, L;
    vector<int> d(N);
    for (int i = 0; i < N; i++) {
        d[i] = b[i] * ma - a[i] * mb;
    }

    for (int i = 1; i < (1<<(N/2)); i++) {
        int tmpd, tmpc;
        tmpd = 0; tmpc = 0;
        for (int j = 0; j < N/2; j++) {
            if((i>>j) & 1){
                tmpd += d[j];
                tmpc += c[j];
            }
        }
        F.push_back(make_pair(tmpd, tmpc));
    }
    for (int i = 1; i < (1<<((N+1)/2)); i++) {
        int tmpd, tmpc;
        tmpd = 0; tmpc = 0;
        for (int j = 0; j < (N+1)/2; j++) {
            if((i>>j) & 1){
                tmpd += d[N/2+j];
                tmpc += c[N/2+j];
            }
        }
        L.push_back(make_pair(tmpd, tmpc));
    }

    sort(ALL(F));
    sort(ALL(L));
    int ans = inINF;
    int tmp;
    for (int i = 0; i < F.size(); i++) {
        int dd = - F[i].first;
        if(dd == 0) continue;
        auto itr = lower_bound(ALL(L), make_pair(dd, 0));
        iint v = *itr;
        if(v.first != dd) continue;
        tmp = v.second + F[i].second;
        ans = min(ans, tmp);
    }
    F.push_back(make_pair(inINF, inINF));
    L.push_back(make_pair(inINF, inINF));
    auto itf = lower_bound(ALL(F), make_pair(0, 0));
    iint vf = *itf;
    if(vf.first == 0){
        ans = min(ans, vf.second);
    }
    auto itl = lower_bound(ALL(L), make_pair(0, 0));
    iint vl = *itl;
    if(vl.first == 0){
        ans = min(ans, vl.second);
    }
    if(ans == inINF){
        printf("%d\n", -1);
        return 0;
    }
    printf("%d\n", ans);

}