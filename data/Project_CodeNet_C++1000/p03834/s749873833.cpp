#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    char s[19];
    cin >> s;
    char* c;
    c = s;
    for (int i=0; i<19; i++) {
        if (*c == ',')
            *c = ' ';
        c++;
    }
    cout << s << flush;

    return 0;
}