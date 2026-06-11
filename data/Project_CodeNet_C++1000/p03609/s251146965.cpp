#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int a , b;
    cin >> a >> b;
    if(a - b <= 0){
        cout << 0 << endl;
    }
    else{
        cout << a - b << endl;
    }
}