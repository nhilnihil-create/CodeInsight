#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;

    if(s.size()==1){
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    rep(i, s.size()-1){
        if(s.at(i)!=s.at(i+1)){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
