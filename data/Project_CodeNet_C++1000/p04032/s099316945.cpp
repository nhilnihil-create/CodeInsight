#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    string s; cin >> s;
    bool f = false;
    int N = s.size();
    REP(i,N) {
        if (i+1<N && s[i]==s[i+1]){
            f = true;
            cout << i+1 << " " << i+2 << endl;
            break;
        }
        else if(i+2<N && s[i]==s[i+2]){
            f = true;
            cout << i+1 << " " << i+3 << endl;
            break;
        }
    }
    if(!f) cout << "-1 -1" << endl;
    return 0;
}