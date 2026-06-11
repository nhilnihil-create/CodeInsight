#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<bool> unvisit(N,false);
    
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    int now = 0;
    while (true) {
        if (unvisit[now]||now==1) {
            break;
        }
        else {
            ans++;
            unvisit[now]=true;
            now=A[now]-1;
        }
    }
    
    if (now == 1) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
    
    return 0;
    
}
