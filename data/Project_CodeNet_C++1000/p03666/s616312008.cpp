#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const string YES = "YES";
const string NO = "NO";

void solve(long long N, long long A, long long B, long long C, long long D){
    /*
    A = abs(B - A);

    --N;
    if (A > D * N) {
        cout << NO << endl;
        return;
    }

    int E = C * N;
    int F = N * (D - C) + 1;
    int G = 2 * C - F;
    cerr << D - C << " " << F << " " << G << " " << E << endl;

    if (G <= 0) {
        cout << YES << endl;
        return;
    }

    if (F + G == 0) {
        cout << (A == 0 ? YES : NO) << endl;
    }

    E %= F + G;

    cerr << A << " " << (A + F + G - E) % (F + G) << endl;

    if ((A + F + G - E) % (F + G) < F) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
    */
    for(int m = 0; m < N; ++m) {
        if (-D * m + C * (N - m - 1) <= B - A && B - A <= -C * m + D * (N - m - 1)) {
            cout << YES << endl;
            return;
        }
    }
    cout << NO << endl;
}

signed main(){
    long long N;
    scanf("%lld",&N);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long D;
    scanf("%lld",&D);
    solve(N, A, B, C, D);
    return 0;
}
