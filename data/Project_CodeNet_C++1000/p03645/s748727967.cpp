#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;
    vector<int> A(200005,0),B(200005,0);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        if(a==1){
            ++A[b];
        }else if(b==1){
            ++A[a];
        }else if(a==n){
            ++B[b];
        }else if(b==n){
            ++B[a];
        }
    }
    rep(i,200001){
        if(A[i]!=0 && B[i]!=0){
            cout << "POSSIBLE" << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}   