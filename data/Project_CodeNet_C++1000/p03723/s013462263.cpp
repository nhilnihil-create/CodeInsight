#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int func(int A, int B, int C) {
    if (A%2 == 1 || B%2 == 1 || C%2 == 1) {
        return 0;
    }
    if (A == B && A == C) {
        return -1;
    }
    
    return func((B+C)/2, (C+A)/2, (A+B)/2) + 1;
}

int main() {
    // input
    int A, B, C;
    cin >> A >> B >> C;
    
    int ans = func(A, B, C);
    cout << ans << "\n";
    return 0;
}


