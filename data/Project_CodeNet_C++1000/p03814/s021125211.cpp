#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    string S;
    cin >> S;
    int first=S.size()-1, last = 0;
    rep(i, S.size()){
        if(S[i] == 'A') first = min(i, first);
        if(S[S.size()-1-i] == 'Z') last = max(last, (int)S.size()-1-i);
    }
    cout << last - first + 1 << endl;

    return 0;
}