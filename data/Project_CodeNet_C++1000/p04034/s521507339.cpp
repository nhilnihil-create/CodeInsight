#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n,1);
    vector<bool> ok(n,false);
    ok[0]=true;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(ok[x]) ok[y]=true;
        v[x]--;
        v[y]++;
        if(v[x]==0) ok[x]=false;
    }
    cout<<accumulate(ok.begin(),ok.end(),0LL)<<endl;
}