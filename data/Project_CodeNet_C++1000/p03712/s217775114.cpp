#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int h,w;
    cin >> h >> w;
    string a[h];
    rep(i, h) cin >> a[i];
    rep(i,h+2){
        if(i==0 || i==h+1){
            rep(_, w + 2) cout << "#";
            cout << endl;
        }
        else{
            cout << "#";
            cout << a[i - 1];
            cout << "#" << endl;
            
        }
    }
}