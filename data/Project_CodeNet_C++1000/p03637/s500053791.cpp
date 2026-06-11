#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    int b1 = 0,b2 = 0,b4 = 0;
    rep(i,n) {
        int a;
        cin >> a;
        if(a%4==0) {
            b4++;
        } else if(a%2 == 0) {
            b2++;
        } else b1++;
    }
    if(b2 == 0) {
        if(b1<=b4+1) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    } else {
        if(b1<=b4) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}