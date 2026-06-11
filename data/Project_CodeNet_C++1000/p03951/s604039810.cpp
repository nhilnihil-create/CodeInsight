#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    string s, t;

    cin >> N >> s >> t;
    int matchLen = 0;
    for(int slide = 0; slide < N; slide++){
        int match = 0;
        for(int i = slide; i < N; i++){
            if(s[i] == t[i-slide]) match++;
        }
        if(match > matchLen) matchLen = match;
    }

    cout << 2*N - matchLen << endl;

    return 0;
}
