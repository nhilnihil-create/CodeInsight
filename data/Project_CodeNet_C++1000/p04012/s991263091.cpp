#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    vi cnt(26);
    string s;
    cin >> s;
    rep(i, s.size()){
        cnt[s[i] - 'a']++ ;
    }

    rep(i, 26){
        if(cnt[i] % 2 != 0){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}