#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,C,K,cnt = 0,cust = 0,time = 0;
    cin >> N >> C >> K;

    vector<int> T(N);

    rep(i, N){
        cin >> T[i];
    }

    sort(T.begin(),T.end());

    cust++;
    time = T[0];
    for(int i = 1;i < N;i++){
        
        if(cust == C || time+K < T[i]){
            cust = 0;
            time = T[i];
            cnt++;
        }
        cust++;
    }
    
    if(cust > 0)
        cnt++;

    cout << cnt << endl;

    return 0;
}