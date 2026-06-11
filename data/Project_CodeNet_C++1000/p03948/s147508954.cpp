#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int N,T;
    cin >> N >> T;
    vector<int> A(N);
    int maxd = 0,mini = INF;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        mini = min(mini,A[i]);
        maxd = max(maxd,A[i] - mini);
    }
    int cnt = 0;
    mini = INF;
    for(int i = 0;i < N;i++){
        mini = min(mini,A[i]);
        if(A[i] - mini == maxd)cnt++;
    }
    cout << cnt << endl;
}   