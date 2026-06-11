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
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    for (ll i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(ALL(v), greater<ll> ());

    // for (ll i = 0; i < N; i++) {
    //     printf("%lld %lld\n", i, v[i]);
    // }


    ll AVE = 0;
    double ans;
    ll cnt = 0; double tmp;
    ll a;
    ll b;
    ll V;

    for (ll i = 0; i < A; i++) {
        AVE += v[i];
    }
    if( AVE == v[A-1] * A ){
        ans = (double)AVE / (double)A;
        a = N;
        for (ll i = 0; i < N; i++) {
            if(v[i] != v[A-1]){
                a = i;
                break;
            }
        }
        for (ll i = A; i < min(a, B)+1; i++) {
            tmp = 1;
            for (ll j = 0; j < i; j++) {
                tmp = tmp * (a - j) / (j+1);
            }
            cnt += (ll)(tmp+0.5);
        }
    }
    else{
        ans = (double)AVE / (double)A;
        V = v[A-1];
        a = A;
        for (ll i = 0; i < N; i++) {
            if(v[i] == V){
                a = i;
                break;
            }
        }
        b = N - a;
        for (ll i = 0; i < N; i++) {
            if(v[i] < V){
                b = i - a;
                break;
            }
        }

        tmp = 1;
        for (ll j = 0; j < A-a; j++) {
            tmp = tmp * (b - j) / (j+1);
        }
        cnt += (ll)(tmp+0.5);
        
    }

    printf("%40.18f\n", ans);
    printf("%lld\n", cnt);

}