#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;
const double PI=acos(-1);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void solve() {
    int N; cin>>N;
    vector<int> a(N);
    int maxi=0,mini=N;
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
        chmax(maxi,a[i]);
        chmin(mini,a[i]);
    }

    if(maxi-mini>1){
        cout<<"No"<<endl;
        return;
    }

    if(maxi==mini){
        if(mini==N-1) cout<<"Yes"<<endl;
        else if(N/mini>=2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return;
    }

    int mini_cnt,maxi_cnt=0;
    for (int i = 0; i < N; ++i) {
        if(a[i]==maxi) maxi_cnt++;
    }
    mini_cnt=N-maxi_cnt;

    if(mini_cnt<maxi&&maxi<=mini_cnt+maxi_cnt/2){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}


#define SINGLE
int main() {
#ifdef SINGLE
    solve();
#else
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        solve();
    }
#endif
    return 0;
}
