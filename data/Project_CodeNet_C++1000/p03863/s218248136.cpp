#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;
    cin>>S;
    int t = S.size();
    if(S[0]==S[t-1]){
        if(t%2==1) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    else {
        if(t%2==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}