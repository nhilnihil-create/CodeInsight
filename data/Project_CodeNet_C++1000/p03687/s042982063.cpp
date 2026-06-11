#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    string tmp = "abcdefghijklmnopqrstuvwxyz";
    int tmpMax = 0;
    int Max = 0;
    int Min = 9999;
    bool chk = false;

    cin >> str;

    for (int i = 0; i < tmp.size()-1; i++){
        tmpMax = 0;
        Max = 0;
        chk = false;

        for (int j = 0; j < str.size(); j++)
        {
            if(tmp.at(i) != str.at(j)){
                tmpMax++;
            }else{
                Max = max(Max, tmpMax);
                tmpMax = 0;
                chk = true;
            }

            if(j == str.size() - 1){
                Max = max(Max, tmpMax);
            }
        }

        if(chk == false) continue;
        Min = min(Min, Max);
    }

    if(Min == 9999) cout << 0;
    else cout << Min;
}