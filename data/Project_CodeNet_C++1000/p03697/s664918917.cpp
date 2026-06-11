#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;

int main() {
    int A,B;
    cin >> A >> B;
    if (A+B>=10) {
        cout << "error" << endl;
    }
    else {
        cout << A+B << endl;
    }
}