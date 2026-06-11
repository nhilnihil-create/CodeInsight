#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> check;

    rep(i, N) {
        cin >> A[i];
        if (check.count(A[i]) == 0) {
            check[A[i]] = 1;
        }
        else {
            check[A[i]]++;
        }
    }

    int kind = (int)check.size();

    cout << ((kind % 2) ? kind : kind - 1) << endl;
    return 0;
}