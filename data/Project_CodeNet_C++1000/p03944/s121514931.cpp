#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
    int w,h,n;
    cin >> w >> h >> n;
    int nx=w,ny=h;
    int mx=0,my=0;
    for(int i=0;i<n;i++){
        int x,y,a;
        cin >> x >> y >> a;
        if(a==1){
            mx=max(mx,x);
        }
        if(a==2){
            nx=min(nx,x);
        }
        if(a==3){
            my=max(my,y);
        }
        if(a==4){
            ny=min(ny,y);
        }
    }
    int W=max(nx-mx,0);
    int H=max(ny-my,0);
    cout << W*H << endl;

}

int main(){
  solve();
  return 0;
}
