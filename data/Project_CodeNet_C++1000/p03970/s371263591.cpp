#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string c="CODEFESTIVAL2016";
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s.at(i)!=c.at(i)) count++;
    }
    cout << count;
}