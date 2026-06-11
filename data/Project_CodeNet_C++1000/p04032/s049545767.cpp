#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    string s; cin >> s;
    for(int i=0; i<s.size(); i++){
        if(i==s.size()-2){
           if(s.at(i)==s.at(i+1)){
            cout << i+1 << " " << i+2 << endl;
            return 0;
           } 
           break;
        }
        else if(s.at(i)==s.at(i+1) || s.at(i)==s.at(i+2)){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
    return 0;
}
