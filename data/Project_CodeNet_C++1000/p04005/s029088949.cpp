#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    if(A%2==0||B%2==0||C%2==0){
        cout << 0 << endl;
        return 0;
    }
    ll ml = max(max(A,B),C);
    if(ml==A){
        cout << B*C << endl;
    }else if(ml==B){
        cout << A*C << endl;
    }else{
        cout << A*B << endl;
    }
    return 0;
}