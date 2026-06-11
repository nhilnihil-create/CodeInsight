#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string divide[4] = {"dream", "dreamer", "erase", "eraser"};
    string ans;
    cin >> ans;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < 4; i++) reverse(divide[i].begin(),divide[i].end());

    bool can = false;
    bool can2 = false;
    for(int i = 0; i < ans.size();){
        for(int a = 0; a < 4; a++){
            if(ans.substr(i, divide[a].size())== divide[a]){
                i += divide[a].size();
                can2 = true;
                break;
            } else {
                can2 = false;
            }
        }
        if(!can2){
            break;
        }
        if(ans.size() == i) can = true;
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}
