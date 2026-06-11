#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin >> s;
    int a = -1, z = -1;
    for (int i=0; i<s.size(); i++){
        if (a==-1 && s[i]=='A') a = i;
        if (z==-1 && s[s.size()-1-i]=='Z') z = s.size()-1-i;
        if (a!=-1 && z!=-1) break;
    }
    cout << z - a + 1 << endl;
    return 0;
}