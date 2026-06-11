#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
    string S;
    cin>>S;
    bool ans=false;
    for(char i='a'; i<='z'; i++){
        if(S.find(i)==-1){
            cout<<i<<endl;
            ans=true;
          	break;
        }
    }
    if(ans==false){
        cout<<"None"<<endl;
    }
    }
