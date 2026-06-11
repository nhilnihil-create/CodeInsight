#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    vector<char> c;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') c.push_back('0'); 
        if(s[i] == '1') c.push_back('1');
        if(s[i] == 'B') {
            if(c.empty()){
                continue;
            }
            else c.pop_back();
        }
    }
    for(int i = 0; i < c.size(); i++)
        cout << c[i];
    cout << endl;
    return 0;
}