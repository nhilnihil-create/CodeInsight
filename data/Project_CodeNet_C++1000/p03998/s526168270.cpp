#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

int main() {
    string a,b,c;
    cin >> a >> b >> c;
    char turn = 'a';
    int a_p=0,b_p=0,c_p=0;
    while(true){
        if(turn=='a'){
            turn = a[a_p];
            a_p++;
        } else if(turn=='b'){
            turn = b[b_p];
            b_p++;
        } else if(turn=='c'){
            turn = c[c_p];
            c_p++;
        }

        if(turn=='a'&&a_p>=a.size()) {
            cout << 'A' << endl;
            return 0;
        }
        if(turn=='b'&&b_p>=b.size()) {
            cout << 'B' << endl;
            return 0;
        }
        if(turn=='c'&&c_p>=c.size()) {
            cout << 'C' << endl;
            return 0;
        }
    } 
}