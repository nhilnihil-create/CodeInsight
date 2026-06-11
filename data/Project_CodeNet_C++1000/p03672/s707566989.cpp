#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 1;;i+2){
        s = s.substr(0, s.size() - i * 2);
        string a = s.substr(0, s.size() / 2);
        string b = s.substr(s.size() / 2, s.size() / 2);
        if(a == b){
            cout << s.size() << endl;
            break;
        }
    }
}