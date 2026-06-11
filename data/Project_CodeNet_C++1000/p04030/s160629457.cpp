#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
    string s; cin >> s;
    vector<char> out;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B'){
            if(out.size()==0) continue;
            out.erase(out.end()-1);
        }else{
            out.push_back((char)(s[i]));
        }
    }
    for(int j=0;j<out.size();j++){
        cout << out[j];
    }
    cout << "\n";
    return 0;
}
