#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;
    int x = 0;
    int maxx = 0;
    rep(i, N){
        if(S[i]=='I') x++;
        else x--;
        maxx = max(x, maxx);
    }
    cout << maxx << endl;

    return 0;
}