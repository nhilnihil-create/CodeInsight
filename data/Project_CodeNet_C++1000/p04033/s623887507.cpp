#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;
    if(a>0) cout << "Positive" << endl;
    else if(a < 0 && b > 0) cout << "Zero" << endl;
    else if(a<0 && b< 0) {
        int cnt = (-a) - (-b)+1;
        if(cnt%2==1) cout << "Negative" << endl;
        else cout << "Positive" << endl;
    }
    return 0;
}