/**
 *  author:   TakeruOkuyama
 *  created:  
**/
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> L(2*N);
    rep(i, 2*N){
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    int ans = 0;
    rep(i, 2*N){
        //cout << L[i];
        if(i % 2 == 0){
            ans += L[i];
        }
    }
    cout << ans << endl;
return 0;}

/**
 * g++ code.cpp
 * ./a.out
 * shift + ctrl + i
**/ 