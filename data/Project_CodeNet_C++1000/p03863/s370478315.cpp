#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s;
int len;

int main() {
    cin >> s; len = s.size();
    if (s[0] == s[len - 1]) {
        if (len % 2) printf("Second\n");
        else printf("First\n");
    }
    else {
        if (len % 2) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}