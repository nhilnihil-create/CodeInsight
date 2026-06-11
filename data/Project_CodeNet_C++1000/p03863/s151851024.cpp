#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if (s.front() == s.back()){
        if ((int)s.size() % 2 == 0) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    else {
        if ((int)s.size() % 2 == 0) cout << "Second" << endl;
        else cout << "First" << endl;
    }
}