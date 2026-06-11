#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n,a,b;
    string s;
    cin >> n >> a >> b >> s;
    int th=0;
    int bb=0;
    rep(i,n){
        if(s.at(i)=='a'){
            if(th<a+b){
                th++;
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        if(s.at(i)=='b'){
            if(th<a+b&&bb<b){
                th++;
                bb++;
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        if(s.at(i)=='c') cout << "No" << endl;
    }

}
