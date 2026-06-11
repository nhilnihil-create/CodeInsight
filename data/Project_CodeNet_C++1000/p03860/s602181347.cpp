#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    string str;
    getline(cin,str);
    bool space = false;
    int len = (int) str.size();
    cout << str[0];
    for (int i = 1; i< len; i++) {
        if ((space == true) && (str[i] != ' ')) {
            cout << str[i];
            space = false;
        }
        if (str[i] == ' ') space = true;
    }
    return 0;
}