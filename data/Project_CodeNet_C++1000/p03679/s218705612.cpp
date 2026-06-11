#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
    int X, A, B;
    cin >> X >> A >> B;
    if (B - A > X) cout << "dangerous" << endl;
    else if (B - A > 0) cout << "safe" << endl;
    else cout << "delicious" << endl;
}
