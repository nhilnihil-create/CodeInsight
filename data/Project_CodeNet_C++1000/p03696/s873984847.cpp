#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a, b) for (int i = (a); i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=3.14159265358979323846;

int main () {
    int N;
    string S;
    cin >> N >>S;
    //S = ")))())";

    int l,r,l_tmp,r_tmp;
    l = l_tmp = r = r_tmp = 0;
    
    rep(i,0,S.size()) {
        if (S[i]=='(') {
            if (r_tmp-l_tmp>0) {
                l+=r_tmp-l_tmp;
                r_tmp = 0;
                l_tmp = 0;
            }
            l_tmp++;
        }
        if (S[i]==')') {
            r_tmp++;
            r++;
        }
    }
    if (r_tmp-l_tmp>0) {
        l+=r_tmp-l_tmp;
    }

    rep(i,0,l) {
        cout << '(';
    }
    cout << S;
    rep(i,0,S.size()-2*r+l) {
        cout << ')';
    }
    cout << endl;


}
