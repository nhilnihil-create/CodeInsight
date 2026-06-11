#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string div[4] = {"dream", "dreamer", "eraser", "erase"};

    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for(int i = 0; i < 4; i++) reverse(div[i].begin(), div[i].end());

    bool ans = true;
    for(int i = 0; i < S.size();){
        bool flag = false;
        for(int j = 0; j < 4; j++){
            string d = div[j];
            if(S.substr(i, d.size()) == d){
                flag = true;
                i += d.size();
            }
        }

        if(!flag){
            ans = false;
            break;
        }
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}