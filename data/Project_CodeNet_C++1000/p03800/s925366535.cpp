#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;
 
//隣り合う二つを決めると残りが決まる
//mod2で考えたりxorをとる
 
int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    rep(i,2) {
        rep(j,2) {
            vector<int> res;
            res.push_back(i);res.push_back(j);
            rep(k,N){
                if(s[k] == 'o') res.push_back(res[k] ^ res[k+1]);
                else res.push_back(res[k] ^ res[k+1] ^ 1);
            }
            if(res[N] == i && res[N+1] == j) {
                for(int l = 1; l <= N; l++){
                    cout << (res[l] ? 'W' : 'S');
                }
                cout << endl;
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}