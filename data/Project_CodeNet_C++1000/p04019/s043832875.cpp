#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string s;
    cin >> s;
    map<char, int> counter;
    for(char c : s){
        counter[c]++;
    }
    if((bool(counter['N']) == bool(counter['S'])) && (bool(counter['W']) == bool(counter['E']))){
        puts("Yes");
    } else
        puts("No");
}