#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int x=0;
    int ans=0;
    for(int i=0; i<n; i++){
        if(s.at(i)=='I'){
            x++;
            ans=max(ans,x);
        }
        else x--;
    }
    cout << ans << endl;
}