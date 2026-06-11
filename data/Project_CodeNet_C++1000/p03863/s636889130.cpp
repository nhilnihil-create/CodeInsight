/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.11 03:01:42
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    string s;cin >> s;
    if (s[0] == s[s.size()-1]) {
        if (s.size() % 2 == 0) {
            puts("First");
        }
        else {
            puts("Second");
        }
    }
    else {
        if (s.size() % 2 == 0) {
            puts("Second");
        }
        else {
            puts("First");
        }
    }
    return 0;
}
