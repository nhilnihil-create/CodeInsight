#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;



int main() {

    string s; cin >> s;
    reverse(s.begin(), s.end());

    vector<string> x = {"dream","dreamer","erase","eraser"};
    for(int i = 0; i < 4; i++) reverse(x[i].begin(), x[i].end());

    while(s.size() != 0) {

        string tmp;
        tmp = s.substr(0,5);

        if(tmp == x[0]) {

            s.erase(0,5);
        
        } else if (tmp == x[2]) {

            s.erase(0,5);
        
        } else {

            tmp = s.substr(0,6);

            if(tmp == x[3]) {

                s.erase(0,6);         

            } else {
            
                tmp = s.substr(0,7);
            
                if(tmp == x[1]) {
            
                    s.erase(0,7);
            
                } else {
                    break;
                }
            }
        }
    }
    if(s.size() > 0) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}



