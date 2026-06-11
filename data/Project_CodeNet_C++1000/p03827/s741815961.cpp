#include <bits/stdc++.h>
using namespace std;

int main() {
    int x=0;
    int maxX = 0;
    int N;
    string S;
    cin >> N;
    cin >> S;

    for(int i=0; S[i]!='\0'; i++)
    {
        if(S[i]=='I') x += 1;
        else x -= 1;

        if(maxX < x) maxX = x;
    }
    cout << maxX << endl;
    return 0;
}