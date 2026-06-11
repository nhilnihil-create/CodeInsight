#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(i%2 == 0) cout << s[i];
    }
    cout << endl;
    return 0;
}