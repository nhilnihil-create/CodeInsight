#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[300][300];
int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>A[i][j];
        }
    }
    ll ans=0;
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            ll m=1LL<<60;
            for(int k=0;k<N;k++) {
                if(k==i||k==j) continue;
                m=min(m,A[i][k]+A[k][j]);
            }
            if(m<A[i][j]) {
                cout<<-1<<endl;
                return 0;
            }
            if(m>A[i][j]) {
                ans+=A[i][j];
            }
        }
    }
    cout<<ans<<endl;
}