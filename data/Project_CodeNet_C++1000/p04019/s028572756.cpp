#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string str;
    cin >> str;
    int n=0,w=0,s=0,e=0;
    rep(i,str.size()){
        if(str[i]=='N') n++;
        else if(str[i]=='W') w++;
        else if(str[i]=='S') s++;
        else e++;
    }
    string ans;
    if( (n==0 && s>0) || (n>0 && s==0)){
        ans = "No";
    }
    else if( (w==0 && e>0) || (w>0 && e==0) ){
        ans = "No";
    }
    else ans = "Yes";
    cout << ans << endl;
    return 0;
}
