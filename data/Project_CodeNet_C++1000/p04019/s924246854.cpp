#include<bits/stdc++.h>
using namespace std;

int main(){
    string st;
    cin >> st;
    bool n = false,s = false,e = false,w = false;
    for(int i = 0;i < st.size();i++){
        if(st[i] == 'N')n = true;
        if(st[i] == 'S')s = true;
        if(st[i] == 'E')e = true;
        if(st[i] == 'W')w = true;
    }
    if(n ^ s || e ^ w)cout << "No" << endl;
    else cout << "Yes" << endl;

}
