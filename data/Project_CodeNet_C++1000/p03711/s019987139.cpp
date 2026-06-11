#include<iostream>
#include<algorithm>

using namespace std;

#define REP(s,e) for(int i=(s);i<(e);i++)

int main(){
    //2 46911
    int x,y;
    int g[]={0,0,1,0,2,0,2,0,0,2,0,2,0,0,0};
    
    cin>>x>>y;
    
    if(g[x]==g[y]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
