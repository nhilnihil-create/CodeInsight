#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void){
    string s;
    cin >> s;
    string div[4] = {"dream","dreamer","erase","eraser"};

    reverse(s.begin(),s.end());
    rep(i,4) reverse(div[i].begin(),div[i].end());

    bool can = true;
    for(int i=0;i<s.size();){
        bool can2 = false;
        rep(j,4){
            string d = div[j];
            if(s.substr(i,d.size()) == d){
                can2 = true;
                i += d.size();
            }
        }
        if(can2 == false){
            can = false;
            break;
        }
    }

    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;
}