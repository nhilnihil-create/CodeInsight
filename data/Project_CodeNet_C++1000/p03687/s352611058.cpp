#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    string S; cin >> S;
    set<char> ST; for(auto c : S) ST.insert(c);
    ll ans = 1e9;
    for(auto ch : S){
        ll Min=0;
        string S_ = S;
        while(1){
            
            bool flag = true;
            string tmp="";
            for(int i = 0; i < S_.size(); i++){
                if(S_[i] != ch) flag = false;
                if(i == S_.size()-1) continue;
                if(S_[i] == ch || S_[i+1] == ch) {
                    tmp+=ch;
                }
                else {
                    tmp += S_[i];
                    flag = false;
                }
            }
            if(flag) break;
            //cout << tmp << " " << Min+1 << endl;
            S_ = tmp;
            
            Min++;
        }
        ans = min(ans, Min);
    }
 
    cout << ans <<endl;
}