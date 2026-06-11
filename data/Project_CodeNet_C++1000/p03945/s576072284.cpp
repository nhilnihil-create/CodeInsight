#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;

    int cnt =0;
    char tmp = s.at(0);
    for(int i=1; i<s.length(); i++){
        if(tmp != s.at(i)){
            cnt++;
        }
        tmp = s.at(i);
    }

    cout << cnt << endl;
    return 0;   
}