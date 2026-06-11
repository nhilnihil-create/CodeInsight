#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s,t;
    cin >> s >> t;

    int ans=0;
    if(s==t){
        ans=n;
    }
    else{
        int cnt=0;
        for (int i = 0; i < n; i++){
            if(s.substr(n-1-i)==t.substr(0,i+1)){
                cnt=i+1;
            }
        }
        ans=2*n-cnt;
    }
    cout << ans << endl;
}