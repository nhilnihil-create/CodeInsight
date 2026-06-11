#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(int N, vector<ll> &A, ll &ans){

    bool pflg = false, nflg = false;
    for(int i = 0; i != N-1; ++i){
        int tmp = A.at(i+1) - A.at(i);

        if(tmp < 0){
            if(pflg == true){
                ++ans;
                pflg = false;
            }
            else nflg = true;
        }
        else if(tmp > 0){
            if(nflg == true){
                ++ans;
                nflg = false;
            }
            else pflg = true;
        }
    }
    ++ans;
    
    return;
}

int main(){

    int N;
    cin >> N;
    vector<ll> A(N);
    for(auto iter = A.begin(); iter != A.end(); ++iter) cin >> *iter;

    ll ans{};
    solver(N, A, ans);

    cout << ans << endl;
    return 0;
}