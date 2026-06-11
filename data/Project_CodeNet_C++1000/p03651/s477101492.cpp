#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int cnt = 0;

bool dfs(vector<int> &A, set<int> &S, set<int> &seen, int k) {
    cnt++;
    if (cnt>100000) return false;
    seen.insert(k);
    if (S.count(k)) return true;
    else {
        rep(i,A.size()) {
            if (cnt>100000) break;
            if (A[i]>k) {
                int next = A[i] - k;
                if (!seen.count(next)) {
                    if (dfs(A,S,seen,next)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

int main(){
    int N,K;
    cin >> N >> K;
    set<int> S,seen;
    vector<int> A;
    rep(i,N) {
        int a;
        cin >> a;
        if(!S.count(a)) {
            A.push_back(a);
            S.insert(a);
        }
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    bool tf = dfs(A,S,seen,K);

    if (tf) {
        cout << "POSSIBLE" << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}
