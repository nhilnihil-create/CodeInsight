#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;


int main(){
    string S;
    cin >> S;
    int len = S.size();
    int l = -1;
    int r = -1;
    rep(i,len - 1){
        if (S[i] == S[i + 1]){
            l = i + 1;
            r = i + 2;
        }
    }
    rep(i,len - 2){
        if (S[i] == S[i + 2]){
            l = i + 1;
            r = i + 3;
        }
    }
    cout << l << " " << r << endl;
}