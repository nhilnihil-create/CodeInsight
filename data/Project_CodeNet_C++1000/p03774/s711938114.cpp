#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

struct DOT{
    int x,y;
    int operator- (const DOT&p)const{
        int dx=x-p.x,dy=y-p.y;
        if(dx<0) dx=-dx;
        if(dy<0) dy=-dy;
        return dx+dy;
    }
    bool operator< (const DOT&p)const{
        if(x==p.x) return y<p.y;
        return x<p.x;
    }
}people[55],check[55];

void Scan(const int &n,DOT* dot){
    for(int i=0;i<n;i++){
        cin>>dot[i].x>>dot[i].y;
    }
}

void solve(const int &n,const int &m){
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=1;j<m;j++){
            int x=people[i]-check[j];
            int y=people[i]-check[ans];
            if(x<y||x==y&&check[j]<check[ans])
                ans=j;
        }
        cout<<ans+1<<endl;
    }
}

int main(){
    int n,m;
    while(cin>>n>>m){
        Scan(n,people);
        Scan(m,check);
        solve(n,m);
    }
    return 0;
}
