#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1000000000 + 7;
const long long INF = 9e18;
const double PI = 3.14159265358979323846;

#define vin(v, N) for (long long i = 0; i < N; i++) cin >> v.at(i)
#define lin(n) long long n; cin >> n
#define chin(x) char x; cin >> x;
#define sin(s) string s; cin >> s;
#define vlin(v, N) vector<long long> v(N); for (long long i = 0; i < N; i++) cin >> v.at(i)

int main(){
    int N, K;
    cin >> N >> K;
    ll int A[N], B[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    ll int ans = INF;
    for (int bit = 0; bit < (1<<N); ++bit){ // 0 1 2 3 4 
        if(__builtin_popcount(bit) < K) continue;
        for(int i = 0; i < N; i++) B[i] = A[i];
        ll int cost = 0;
        vector<int> ind;
        ll int max_num = A[0];
        for(int i = 1; i < N; i++){ // bit 0 bit 1 => 0 bit 2 => 1
            if(bit & (1 << i)){
                B[i] = max(max_num + 1, B[i]);
                cost += B[i] - A[i];
                max_num = max(max_num, B[i]);
            }
            else max_num = max(max_num, A[i]);
        }

        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}

