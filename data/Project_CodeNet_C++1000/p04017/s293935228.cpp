#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, L, Q;
    cin >> N;
    vector<int> X(N);
    for(int i=0; i<N; i++) cin >> X[i];
    cin >> L >> Q;

    vector<vector<int>> nxt(17, vector<int>(N));
    int r = 0;
    for(int l=0; l<N; l++){
        while(r<N && X[r]-X[l] <= L) r++;
        nxt[0][l] = r-1;
    }
    for(int k=1; k<17; k++) for(int i=0; i<N; i++) nxt[k][i] = nxt[k-1][nxt[k-1][i]];

    for(int i=0; i<Q; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a, b);
        int ans = 0;
        for(int k=16; k>=0; k--) if(nxt[k][a] < b){
            ans += 1<<k;
            a = nxt[k][a];
        }
        cout << ans+1 << endl;
    }
}