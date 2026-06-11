#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N,M;
    cin>>N>>M;

    vector<int> anser(N);

    rep(i,M) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        anser[a]+=1;
        anser[b]+=1;
    }

    rep(i,N) {
        cout<<anser[i]<<endl;
        
    }
}