#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int ans = A*B >= C*D ? A*B : C*D;
    cout << ans << endl;
    return 0;
}