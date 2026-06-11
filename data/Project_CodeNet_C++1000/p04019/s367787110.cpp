#include <iostream>
#include <string>
#include <map>
using namespace std;
bool solve(string S);

bool solve(string S){
    map<char,int> ma; // あるなら 1、ないなら 0
    for (int i = 0; i < S.size(); ++i){
        if (ma.count(S[i])) ma[S[i]] = 1;
        else ma[S[i]] = 1;
    }
    if (ma['N'] != ma['S']) return false;
    if (ma['W'] != ma['E']) return false;
    return true;
}

int main() {
    string S; cin >> S;
    if (solve(S)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
