#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(b<c){
        cout << 0 << endl;
        return 0;
    }

    if(d<a){
        cout << 0 << endl;
        return 0;
    }

    if(b<=d){
        if(a<=c) cout << b - c << endl;
        else cout << b - a << endl;
    }
    else{
        if(c<=a)cout << d - a << endl;
        else cout << d - c << endl;
    }
    return 0;
}
