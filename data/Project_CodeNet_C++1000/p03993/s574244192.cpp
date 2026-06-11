#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N;
    cin >> N;
    map<int,int> M;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        M[i+1] = a;
    }
    int ans = 0;
    for(auto m : M){
        if(M[m.second] == m.first){
            ans++;
        }
    }
    cout << ans/2 << endl;

    return 0;
}