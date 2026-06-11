#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<int> cnt(2);
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') cnt[1]++;
        else {
            if (cnt[1] > 0) cnt[1]--;
            else cnt[0]++;
        }
    }
    string ans = string(cnt[0], '(') + S + string(cnt[1], ')');
    cout << ans << '\n';
}
