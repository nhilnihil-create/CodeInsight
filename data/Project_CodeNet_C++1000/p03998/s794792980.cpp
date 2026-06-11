#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    vector <string> S(3);
    rep(i,3) cin >> S[i];

    int la=S[0].size(), lb=S[1].size(), lc=S[2].size();

    int ac=0, bc=0, cc=0;
    int tmp = 0;
    string turn= "a";
    bool ok=true;
    while(ok){
        if(turn == "a"){
            if(ac >= S[0].size()){
                ok = false;
                break;
            }
            turn = S[0][ac];
            ac++;
        }
        else if(turn == "b"){
            if(bc >= S[1].size()){
                ok = false;
                break;
            }
            turn = S[1][bc];
            bc++;
        }
        else{
            if(cc >= S[2].size()){
                ok = false;
                break;                
            }
            turn = S[2][cc];
            cc ++;
        }
    }

    if(turn == "a") cout << "A" << endl;
    else if(turn == "b") cout << "B" << endl;
    else cout << "C" << endl;


}