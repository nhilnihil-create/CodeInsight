#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string correct = "CODEFESTIVAL2016";

    int convNeed = 0;

    for(int i=0;i<s.size();i++){
        if(s[i]!=correct[i])convNeed++;
    }

    cout << convNeed << endl;

    return 0;
}
