#include <bits/stdc++.h>
using namespace std;

int main(){

    string o, e;
    cin >> o >> e;

    int num = o.size() + e.size(), o_idx = 0, e_idx = 0;
    string ans;
    for (int i=0; i<num; i++){
        int temp = i + 1;
        if (temp%2 == 0){
            ans += e.at(e_idx);
            e_idx++;
        }
        else {
            ans += o.at(e_idx);
            o_idx++;
        }
    }
    cout << ans << endl;
    return 0;
}