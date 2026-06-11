#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string S = "";
    char x;
    bool left = true;
    getline(cin, S);
    for (int i = 0; i < S.size(); i++)
    {
        if (S.at(i) == ' ' && left)
        {
            x = S.at(i + 1);
            break;
        }
        
    }
    cout << 'A' << x << 'C' << endl;

}