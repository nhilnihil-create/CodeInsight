#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < S.length() - 1; i++)
    {
        if (S[i] != S[i + 1])
        {
            ans++;
        }
        
    }
    cout << ans << endl;
    return 0;
    
}