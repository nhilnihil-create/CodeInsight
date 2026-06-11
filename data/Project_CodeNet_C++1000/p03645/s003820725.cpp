#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    set<pair<int,int>> s;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        s.emplace(a,b);
    }
    
    for(int i=2;i<n;i++){
        if(s.count(make_pair(1,i)) && s.count(make_pair(i,n))){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}