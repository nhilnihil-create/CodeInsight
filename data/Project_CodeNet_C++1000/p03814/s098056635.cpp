/*
      author  : nishi5451
      created : 12.08.2020 22:17:17
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int first,last;
    rep(i,int(s.size()))
        if(s[i]=='A'){
            first=i;
            break;
        }
    rep(i,int(s.size()))
        if(s[i]=='Z') last=i;
    
    cout << last-first+1 << endl;
    return 0;
}   