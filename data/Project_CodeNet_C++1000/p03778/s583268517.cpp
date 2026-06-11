#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int w, a, b;
    cin >> w >> a >> b;
    if (b > a){
        if (b - w - a > 0) out(b-w-a);
        else out(0);    
    }
    else {
        if (a - w - b > 0) out(a-w-b);
        else out(0);
    }
    
}