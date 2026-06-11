#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,L;
    cin >> N >> L;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    int mid = -1;
    rep(i,N-1){
        if(A[i]+A[i+1]>=L){
            mid = i;
            break;
        }
    }
    if(mid<0){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for(int i=0;i<mid;i++){
        cout << i+1 << endl;
    }
    for(int i=N-2;i>mid;i--){
        cout << i+1 << endl;
    }
    cout << mid+1 << endl;
    return 0;
}