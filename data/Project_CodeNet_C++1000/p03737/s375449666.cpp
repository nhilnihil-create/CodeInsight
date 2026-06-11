#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    string s,t,u;
    cin >> s >> t >> u;
    s.at(0) -= 32;
    t.at(0) -= 32;
    u.at(0) -= 32;
    cout << s.at(0);
    cout << t.at(0);
    cout << u.at(0);
    cout << endl;
}