#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count=0;
    string a="YAKIaaaaaa";
    for(int i=0;i<s.size();i++){
        if(s.at(i)==a.at(i)) count++;
    }
    if(count == 4) cout << "Yes";
    else cout << "No";
}