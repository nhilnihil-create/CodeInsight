#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    int n = a.length() + b.length() + c.length();
    int na=0,nb=0,nc=0;
    char now = 'a';
    rep(i,n){
        if(now == 'a'){
            if(a[na] == 'a') now = 'a';
            else if(a[na] == 'b') now = 'b';
            else if(a[na] == 'c') now = 'c';
            na++;
            if(na == a.length()+1){
                cout << "A" << endl;
                return 0;
            }
        }else if(now == 'b'){
            if(b[nb] == 'a') now = 'a';
            else if(b[nb] == 'b') now = 'b';
            else if(b[nb] == 'c') now = 'c';
            nb++;
            if(nb == b.length()+1){
                cout << "B" << endl;
                return 0;
            }
        }else if(now == 'c'){
            if(c[nc] == 'a') now = 'a';
            else if(c[nc] == 'b') now = 'b';
            else if(c[nc] == 'c') now = 'c';
            nc++;
            if(nc == c.length()+1){
                cout << "C" << endl;
                return 0;
            }
        }
    }
    return 0;
}