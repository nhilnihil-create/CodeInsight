#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int A,B;
    cin >> A >> B;
    if(A + B >= 10) {
        cout << "error" << endl;
    }
    else {
        cout << A + B << endl;
    }
}