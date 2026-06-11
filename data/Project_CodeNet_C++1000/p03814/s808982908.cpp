#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;
int main(){
    string s;
    cin>>s;
    int fi, la;
    for (int i=0; i<s.size(); i++){
        if (s[i] == 'A'){
          fi = i;
          break;
        }
    }
    reverse(s.begin(), s.end());
    for (int i=0; i<s.size(); i++){
        if (s[i] == 'Z'){
          la = s.size() - i;
          break;
        }
    }
    cout << la-fi;
}