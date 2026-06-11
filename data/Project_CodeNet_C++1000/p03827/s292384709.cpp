#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int x = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='I')x++;
        if(s[i]=='D')x--;
        ans = max(ans,x);
    }
    cout << ans << endl;
    return 0;
}