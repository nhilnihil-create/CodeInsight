#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    while(1)
    {
        if(S.empty()) break;
        if(S.substr(S.size()-5, 5)=="dream")
        {
            S.erase(S.size()-5, 5);
        }else if(S.substr(S.size()-5, 5)=="erase")
        {
            S.erase(S.size()-5, 5);
        }else if(S.substr(S.size()-6, 6)=="eraser")
        {
            S.erase(S.size()-6, 6);
        }else if(S.substr(S.size()-7, 7)=="dreamer")
        {
            S.erase(S.size()-7, 7);
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}