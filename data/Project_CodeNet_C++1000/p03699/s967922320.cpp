#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;

int N;
V<int> S;

int main() {
    cin >> N;
    S.resize(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    sort(all(S));
    int sum = accumulate(all(S), 0);

    for(int i = 0; i < N; i++){
        if(sum % 10 != 0){
            cout << sum << endl;
            return 0;
        }
        if(S[i] % 10 != 0) sum -= S[i];
    }
    cout << 0 << endl;
}
