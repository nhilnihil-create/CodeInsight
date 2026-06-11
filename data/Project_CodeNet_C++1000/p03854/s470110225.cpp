#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    string data[] = {"dream", "dreamer", "erase", "eraser"};

    for(int i = 0 ; i < 4 ; i++){
        reverse(data[i].begin(), data[i].end());
    }

    int now = 0;
    while(1){
        bool flag = false;
        for(int i = 0 ; i < 4 ; i++){
            if(s.substr(now, data[i].size()) == data[i]){
                flag = true;
                now += data[i].size();
                break;
            }
        }
        if(now >= s.size()){
            cout << "YES" << endl;
            return 0;
        }
        if(!flag){
            cout << "NO" << endl;
            return 0;
        }
    }

}