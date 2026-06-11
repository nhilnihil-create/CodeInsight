#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count =0;
    int mx=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='I'){
            count++;
            mx = max(count,mx);
        }else if(s[i]=='D'){
            count--;
        }
    }
    cout<<mx <<endl;
}