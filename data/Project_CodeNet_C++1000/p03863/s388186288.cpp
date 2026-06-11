#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    bool b = (*s.begin() == *(--s.end()));
    if ((s.size() - b) % 2 == 1){
        cout << "First" << endl;
    }else cout << "Second" << endl;
}