#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    string s; cin >> s;
    string t="";
    rep(i, s.size()){
        dump(t);
        if(s.at(i)==','){
            cout << t << " ";
            t = "";
            continue;
        }
        else{
            t.push_back(s.at(i));
        }
    }
    cout << t << endl;
    return 0;
}
