#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main(){
    string s;
    cin >> s;
    string dream,dreamer,erase,eraser;
    dream = "maerd";
    dreamer = "remaerd";
    erase = "esare";
    eraser = "resare";
    bool can = true;
    vector<string> divide{dream,dreamer,erase,eraser};
    reverse(s.begin(),s.end());
    for(int i = 0; i < s.size();){
        bool can2 = false;
        for(int j = 0; j < 4; j++){
            string d = divide.at(j);
            if(s.substr(i,d.size()) == d){
                can2 =true;
                i += d.size();
            } 
        }
        if(!can2){
            can = false;
            break;
        }
    }
    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;
}
