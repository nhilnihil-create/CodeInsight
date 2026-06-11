#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int w,h,n;
    cin>>w>>h>>n;
    
    int minx=0, maxx=w, miny=0, maxy=h;
    int x,y,a;
    
    rep(i,n){
        cin>>x>>y>>a;
        if(a==1)minx=max(minx,x);
        if(a==2)maxx=min(maxx,x);
        
        if(a==3)miny=max(miny,y);
        if(a==4)maxy=min(maxy,y);
    }
    if(maxx<minx || maxy<miny )cout << 0 <<endl;
    else cout << (maxx-minx)*(maxy-miny) << endl;
    
    return 0;
}