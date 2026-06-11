#include <bits/stdc++.h>

#define mod 1000000007;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    

    for(int i = 0 ; i + 1 < S.size(); i++)
    {
        if(S[i] == S[i+1])
        {
            cout << i + 1 << " " << i + 2;
            return 0;
        }

        if(i + 2 < S.size() && S[i] == S[i+2])
        {
            cout << i + 1 << " " << i +3;
            return 0;
        }


    }
    cout << "-1 -1";
}