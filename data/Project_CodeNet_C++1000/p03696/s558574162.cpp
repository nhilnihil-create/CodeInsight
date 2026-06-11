#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    int mina = 0;
    int maxb = 0;
    rep(i, n){
        if(s.at(i) == '('){
            a++;
            b++;
        }else{
            a--;
            b--;
        }
        if(b < 0) b = 0;
        if(mina > a) mina = a;
        if(maxb < b) maxb = b;
    }
    rep(i, -mina) s = '(' + s;
    rep(i, b) s += ')';
    cout << s << endl;
    return 0;
}