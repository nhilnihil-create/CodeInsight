#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N;
    cin >> N;
    vector<P>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(),A.end());
    int res = 0;
    for(int i = 0; i < N; i++) {
        if(A[i].second%2 != i%2) {
            res++;
        }
    }
    cout << res/2 << endl;
}
