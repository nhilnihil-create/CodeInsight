#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    bool ans = false;
    rep(i,N){
        if (vec[i] % 2 == 1){
            c0++;
        }
        else if (vec[i] % 4 == 2){
            c1++;
        }
        else{
            c2++;
        }
    }
    if (c1 == 0){
        if (c0 <= c2 + 1) ans = true;
    }
    else{
        if (c0 <= c2) ans = true;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

