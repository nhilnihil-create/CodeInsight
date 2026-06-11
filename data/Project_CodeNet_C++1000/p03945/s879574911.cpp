#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    char c = s.at(0);
    int cnt = 1;
    for(int ix=0;ix<s.size();ix++){
        if(c != s.at(ix)){
            cnt++;
            c = s.at(ix);
        }
    }
    cout << cnt-1 << endl;
}