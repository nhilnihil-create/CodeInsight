#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)n;++i)

int main() {
    int n,m;cin>>n>>m;
    vector<int>a;
    vector<int>b;
    vector<int>c;    
    rep(i,m){
        int tmp1,tmp2;cin>>tmp1>>tmp2;
        if(tmp1 == 1)a.push_back(tmp2);
        if(tmp2 == n)b.push_back(tmp1);        
    }
    int na = a.size();
    int nb = b.size();

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(na>0)c.push_back(a[0]);
    if(nb>0)c.push_back(b[0]);    
    
    for(int i=1;i<na;++i)if(a[i]!=a[i-1])c.push_back(a[i]);
    for(int i=1;i<nb;++i)if(b[i]!=b[i-1])c.push_back(b[i]);
    
    sort(c.begin(),c.end());
    int nc = c.size();
    rep(i,nc-1)if(c[i+1]==c[i]){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }

    cout<<"IMPOSSIBLE"<<endl;
	return 0;
    
}

