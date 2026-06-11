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

int main() {
    int N,L; cin>>N>>L;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    int point=-1;
    for (int i = 0; i < N - 1; ++i) {
        if(a[i]+a[i+1]>=L){
            point=i;
            break;
        }
    }
    if(point==-1){
        cout<<"Impossible"<<endl;
        return 0;
    }

    cout<<"Possible"<<endl;
    for (int i = 1; i <= point; ++i) {
        cout<<i<<endl;
    }
    for (int i = N-1; i > point; --i) {
        cout<<i<<endl;
    }

    return 0;
}
