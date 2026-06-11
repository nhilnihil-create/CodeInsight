#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int X , A , B;
    cin >> X >> A >> B;
    if(A >= B){
        cout << "delicious" << endl;
    }
    else if(A + X >= B){
        cout << "safe" << endl;
    }
    else{
        cout << "dangerous" << endl;
    }
}
