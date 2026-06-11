#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    cout << ( s.size()%2 ^ (*s.begin()==*s.rbegin()) ? "First" : "Second") << endl;
}