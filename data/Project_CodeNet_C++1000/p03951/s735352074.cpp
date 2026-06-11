#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int cnt = 0;
    int n; cin >> n;
    string s, t; cin >> s >> t;
    
    for(int i = 0; i < n; i++){
        int k = 0, cnt = 0;
        for(int j = i; j < n; j++){
            if(s[j] == t[k++]){
                cnt++;
            }else{
                break;
            }
        }
        if(cnt == n - i){
            put(2 * n - cnt);
            return 0;
        }
    }
    put(2 * n);
}