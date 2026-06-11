#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    string s;cin >> s;
    string a;
    for(int i = 0; i < 4; i++){
        a.push_back(s[i]);
    }
    a.push_back(' ');
    for(int i = 4; i < s.size(); i++){
        a.push_back(s[i]);
    }
    cout << a << endl;
}