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

    string s;
    cin >> s;

    int size = s.size();

    for(int i = size - 2; i >= 0; i = i - 2){

        if(s.substr(0, i / 2) == s.substr(i / 2, i / 2)){
            cout << i << endl;
            break;
        }
    }


    return 0;
}
/*
|S|が小さいので全探索
*/