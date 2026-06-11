#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    string s; cin >> s;
    string t;
    for(int i=0; i<s.size(); i++){
        if((i+1)%2){
            t+=s.at(i);
        }
    }

    cout << t << endl;
    return 0;
}
