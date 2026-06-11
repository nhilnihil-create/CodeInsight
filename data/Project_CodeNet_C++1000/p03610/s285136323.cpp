#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    string S;cin>>S;
    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 0) printf("%c", S[i]);
    }
    cout << endl;
    return 0;
}