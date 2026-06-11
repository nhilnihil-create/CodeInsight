#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    ll a,b;
    char op;
    cin >> a >> op >> b;
    if(op == '+'){
        cout << a + b << endl;
        return 0;
    }else{
        cout << a - b << endl;
        return 0;
    }
    return 0;
}