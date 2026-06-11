#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(i % 2 != 0) continue;
        cout << s.at(i);
    }
    cout << endl;
}
