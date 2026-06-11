#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    string ans;

    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '0'){
            ans += "0";
        }
        else if(s[i] == '1'){
            ans += "1";
        }
        else if(!ans.empty()){

            ans.pop_back();
        }
    }

    cout << ans << endl;

    return 0;
}
