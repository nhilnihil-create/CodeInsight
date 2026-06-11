#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    string s;
    rep(i,h){
        rep(k,w){
            cin >> s;
            if(s=="snuke"){
                cout << (char)('A'+k) << i+1 << endl;
                break;
            }
        }
    }

    return 0;
}