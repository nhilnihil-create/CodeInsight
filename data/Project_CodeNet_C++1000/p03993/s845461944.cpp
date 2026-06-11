#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        A[i]--;
    }
    int cnt = 0;
    rep(i,N){
        if(A[A[i]]==i){
            cnt++;
        }
    }
    cout << cnt/2 << endl;
    return 0;
}