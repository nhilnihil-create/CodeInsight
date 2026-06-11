#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long


int comb[60][60];

void solve(long long N, long long A, long long B, std::vector<long long> v){
    sort(ALL(v));
    reverse(ALL(v));

    double sum = 0;
    for(int i = 0; i < A; ++i) {
        sum += v[i];
    }

    printf("%.10f\n", sum / A);

    int a = 0;
    for(int i = 0; i < N; ++i) if (v[A - 1] == v[i]) {
        a = i;
        break;
    }

    int m = 0;
    for(int i = 0; i < N; ++i) if(v[i] == v[A - 1]) m++;

    for(int i = 0; i < 60; ++i) {
        comb[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    int res = 0;
    if (v[0] == v[A - 1]) {
        for (int i = A; i <= B; ++i) {
            if (v[i - 1] != v[A - 1]) {
                continue;
            }
            int n = i - a;
            res += comb[m][n];
        }
    } else {
        res += comb[m][A - a];
    }

    cout << res << endl;
}

signed main(){
    long long N;
    scanf("%lld",&N);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    std::vector<long long> v(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&v[i]);
    }
    solve(N, A, B, std::move(v));
    return 0;
}
