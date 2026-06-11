#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a, b) for (int i = (a); i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=3.14159265358979323846;

int main () {
    int N;
    cin >> N;
    int A[N];
    rep(i,0,N) {
        cin >> A[i];
    }
    int d = 0;
    int ans = 1;
    int now = A[0];
    rep(i,0,N) {
        if (now==A[i]) {
            now = A[i];
            continue;
        }
        else if (A[i]-now>0 && d >= 0) {
            d = 1;
            now = A[i];
            continue;
        }
        else if (A[i]-now<0 && d<=0) {
            d = -1;
            now = A[i];
            continue;
        }
        else {
            now = A[i];
            ans++;
            d = 0;
        }
    }
    cout << ans << endl;
}