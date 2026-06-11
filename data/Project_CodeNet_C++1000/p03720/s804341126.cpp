#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> city(N);
    
    int a, b;
    rep(i, M){
        cin >> a >> b;
        city.at(a - 1) += 1;
        city.at(b - 1) += 1;
    }

    rep(i, N){
        cout << city.at(i) << endl;
    }
}