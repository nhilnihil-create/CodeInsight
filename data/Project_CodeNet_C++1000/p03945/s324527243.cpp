#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;
const long long MOD = (long long)1e9 + 7;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] != s[i]){
            ans++;
        }
    }
    cout << ans << endl;
}
