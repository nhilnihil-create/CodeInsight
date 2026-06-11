#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)



int main(){
    string s;
    cin>>s;

    int l = s.length();

    rep(i,l){
        if((i+1)%2==1) cout<<s[i];
    }
    cout<<endl;


    return 0;
}