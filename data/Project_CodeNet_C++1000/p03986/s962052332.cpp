#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


int main(){
    string X;
    cin >> X;
    vector<char> A;

    rep(i,X.size()) {
        if (A.size()==0) {
            A.push_back(X[i]);
        }
        else {
            if (A.back()=='S' && X[i]=='T') {
                A.pop_back();
            }
            else {
                A.push_back(X[i]);
            }
        }
    }
    cout << A.size() << endl;
}    