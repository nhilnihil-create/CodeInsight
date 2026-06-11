
#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;

long long com[51][51];
int main () {
    com[0][0] = 1;
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];
        }
    }

    int N, A, B; cin >> N >> A >> B;
    vector<long long> v(N);
    for (int i = 0; i < N; ++i ) cin >> v[i];
    sort(v.begin(), v.end(), greater<long long>());

    //最大値
    long long sum = 0;
    for (int i = 0; i < A; ++i) sum += v[i];
    double ave = (double)(sum) / A;

    //小さいやつの個数
    long long res = 0;
    int num = 0;
    for (int i = 0; i < N; ++i) if (v[i] == v[A-1]) ++num;
    if (v[0] == v[A-1]) {
        for (int j = A; j <= B; ++j) {
            res += com[num][j];
        }
    }
    else {
        int a = 0;
        for (int i = 0; i < A; ++i) if (v[i] == v[A-1]) ++a;
        res = com[num][a];
    }

    cout << fixed << setprecision(10) << ave << endl;
    cout << res << endl;
}