#include <bits/stdc++.h>
using namespace std;


void solve(std::string s){
    cout << s.substr(0,4) + " " + s.substr(4,8) << endl;
}

int main(){
    std::string s;
    std::cin >> s;
    solve(s);
    return 0;
}
