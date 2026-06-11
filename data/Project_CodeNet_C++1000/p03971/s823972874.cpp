#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int limit = a + b, count = 0;
    rep(i, n) {
        if(s[i] == 'a') {
            if(limit > 0){
                cout << "Yes" << endl;
                limit--;
            }else{
                cout << "No" << endl;
            }
        }
        if(s[i] == 'b'){
            if(limit > 0 && count < b){
                cout << "Yes" << endl;
                limit--;
                count++;
            }else{
                cout << "No" << endl;
            }
        }
        if(s[i] == 'c')
            cout << "No" << endl;
    }
    return 0;
}