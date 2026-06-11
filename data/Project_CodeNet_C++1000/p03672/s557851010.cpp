#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string S;
    cin >> S;
    bool flag = false;
    for (int i = (int)S.size()-1; i >= 0; i--) {
        string str1 = S.substr(0,S.size()/2);
        string str2 = S.substr(S.size()/2, S.size()-1);
        if (str1 == str2 && flag) {
            cout << S.size() << endl;
            return 0;
        }
        S.erase(i);
        flag = true;
    }
    cout << 0 << endl;
}