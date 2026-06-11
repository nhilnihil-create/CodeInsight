#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n; string s;
    cin>>n>>s;
    int a=0,b=0;
    rep(i,n){
        if(s[i]=='(')a++;
        if(s[i]==')'&&a>0){a--;}
        else if(s[i]==')'&&a==0)b++;
    }
    string t,u;
    if(a>0)t=string(a,')');
    if(b>0)u=string(b,'(');
    if(a>0)s+=t;
    if(b>0)s=u+s;
    cout<<s<<endl;
}