#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int sz;
    sz = s.size();
    int mn, mx;
    mn = sz;
    mx = 0;
    for(int i=0; i<sz; i++){
        if(s[i]=='A'){
            mn = min(mn,i);
        }
        if(s[i]=='Z'){
            mx = max(mx,i);
        }
    }
    cout << mx-mn+1 << endl;
}


