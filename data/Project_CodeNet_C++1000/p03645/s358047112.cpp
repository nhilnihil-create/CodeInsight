#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M;
    map<string, int>mp;
    for (int i = 0; i < M; i++) {
        string a;
        string b;
        cin >> a >> b;
        mp["1" + a + b]++;
        mp[a + b + to_string(N)]++;
    }
    
    for (auto itr = mp.begin(); itr != mp.end(); itr++){
        if (itr->second > 1) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}