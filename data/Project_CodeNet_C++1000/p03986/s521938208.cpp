#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string x;
    cin>>x;
    int s=0,t=0,n=x.size();
    rep(i,n){
        if(x[i]=='S')s++;
        if(x[i]=='T'&&s==0)t++;
        if(x[i]=='T'&&s!=0)s--;
    }
    cout<<s+t<<endl;
}