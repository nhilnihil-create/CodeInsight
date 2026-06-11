#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int cnta = 0;
    int cntb = 0;

    rep(i,n){
        char ch = s[i];
        if(ch == 'a'){
            if(cnta+cntb < a+b) {
                cout << "Yes" << endl;
                cnta++;
            }else cout << "No" << endl;
        }else if(ch == 'b'){
            if(cnta+cntb < a+b && cntb < b){
                cout << "Yes" << endl;
                cntb++;
            }else cout << "No" << endl;
        }else cout << "No" << endl;
    }
}