#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int A , B;
    cin >> A >> B;
    if(A + B <= 23){
        cout << A + B << endl;
    }
    else{
        cout << A + B - 24 << endl;
    }
}