#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

int main(){

    ll N,A,B;

    cin >> N >> A >>B;

    if (A==B) {
        cout << 1 << endl;
    }
    else if (A>B) {
        cout << 0 << endl;
    }
    else if (N==1 && A!=B) {
        cout << 0 << endl;
    }
    else {
        ll a = A+B+(N-2)*B;
        ll b = A+B+(N-2)*A;
        cout << a-b+1 << endl;
    }

}
