#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(){
    string s;
    cin >> s;

    set<char> T;

    for(long long i = 0; i < s.size(); i++) T.insert(s[i]);
    
    if(T.size() == s.size()) printf("yes\n");
    else printf("no\n");

    return 0;
}