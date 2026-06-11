#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
    int N, L;

    cin >> N >> L;

    vector<string> S;

    int i;

    for(i=0; i<N+1; i++){
        string s;
        getline(cin, s);
        S.push_back(s);
    }

    sort(S.begin(), S.end());

    for(i=0; i<N+1; i++){
        cout << S[i];
    }
}
