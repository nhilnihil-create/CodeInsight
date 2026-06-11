#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    string s;cin>>s;
    int n = s.size();
    
    int a[4];
    rep(i,4)a[i]=0;
    rep(i,n){
        if(s[i]=='N')++a[0];
        if(s[i]=='S')++a[1];
        if(s[i]=='E')++a[2];
        if(s[i]=='W')++a[3];
    }
    int ans = 0;
    if(a[0] > 0 && a[1] == 0)ans=1;
    if(a[1] > 0 && a[0] == 0)ans=1;
    if(a[2] > 0 && a[3] == 0)ans=1;
    if(a[3] > 0 && a[2] == 0)ans=1;

    if(ans==1)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
	return 0;
}