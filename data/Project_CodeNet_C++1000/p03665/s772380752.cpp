#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mypow(int x,int n){
    if(n==0)
        return 1;
    if(n%2==1)
        return mypow(x,n-1)*x;
    int tmp=mypow(x,n/2);
    return tmp*tmp;
}
signed main() {
    int N,P;
    cin >> N >> P;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i]%2) {
            cout << mypow(2,N-1) << endl;
            return 0;
        }
    }
    if(!P) {
        cout << mypow(2,N) << endl;
    }
    else {
        cout << 0 << endl;
    }
}