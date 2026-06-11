#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define Sort(x) sort((x).begin(),(x).end())
#define Sort2(x) sort((x).begin(),(x).end(), greater<int>())
const int INF = 1001001001;

int main()
{
    int w,h,n; cin >> w >> h >> n;
    int x1=0,x2=w,y1=0,y2=h;
    rep(i,n){
        int xi,yi,a; cin >> xi >> yi >> a;
        if(a==1) x1 = max(x1,xi);
        if(a==2) x2 = min(x2,xi);
        if(a==3) y1 = max(y1,yi);
        if(a==4) y2 = min(y2,yi);
    }
    if(x2-x1 <= 0 || y2-y1 <= 0) cout << 0 << endl;
    else cout << (x2-x1) * (y2-y1) << endl;
}

/*
Ctrl+@
g++ a.cpp
./a.out
*/
