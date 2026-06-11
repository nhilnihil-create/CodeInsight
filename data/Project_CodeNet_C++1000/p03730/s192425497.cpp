#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    int a,b,c;
    cin >> a >> b >> c;

    map<int, int> m;
    int tmp = a;

    while(true){
        if(m[tmp % b] == 1) break;

        m[tmp % b] = 1;
        tmp += a;
    }

    cout << (m[c] == 1 ? "YES" : "NO") << endl;
    


    return 0;
}
/*
|S|が小さいので全探索
*/