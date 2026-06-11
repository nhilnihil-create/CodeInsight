#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    string s; cin>>s;
    int l=s.length();
    int ans=0;
    for(int i=1; i*2<l; ++i){
        string t=s.substr(0,i), u=s.substr(i,i);
        if(t==u) ans=i;
    }
    cout<<ans*2<<endl;
    return 0;
}