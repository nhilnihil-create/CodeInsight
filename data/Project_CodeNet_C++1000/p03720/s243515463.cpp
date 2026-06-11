#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    vector<int> b(m);
    vector<int> c(n,0);
    rep(i,m){
        cin>>a.at(i)>>b.at(i);
        cout<<endl;
    }
    rep(i,m){
        c.at(a.at(i)-1)++;
        c.at(b.at(i)-1)++;
    }
    rep(i,n){
        cout<<c.at(i)<<endl;
    }

    cout<<endl;
}