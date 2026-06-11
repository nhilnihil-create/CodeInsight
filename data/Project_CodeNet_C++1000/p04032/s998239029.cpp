#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
int n, m, q;
int a[51], b[51], c[51], d[51];
int v[11];
 
int main() {
    string S;
    cin >> S;
    bool isfind = false;
    rep(i, 0, S.size()-1){
        if(S[i] == S[i+1]){
            cout << i+1<<" "<<i+2 << endl;
            isfind = true;
            break;
        }
    }
    if (!isfind){
        rep(i, 0, S.size()-2){
            if(S[i] == S[i+2]){
                cout << i+1<<" "<<i+3 << endl;
                isfind = true;
                break;
            }
        }
    }
    if (!isfind){
       cout << "-1"<<" "<<"-1" << endl;
    }
    
    return 0;
}
