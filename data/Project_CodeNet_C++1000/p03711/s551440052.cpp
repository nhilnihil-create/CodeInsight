#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int x,y; cin >> x >> y;
    int xok;
    int yok;
    if (x==1 || x==3 || x==5 || x==7 || x==8 || x==10 ||x==12) xok=1;
    if (x==4 || x==6 || x==9 || x==11) xok=2;
    if (x==2) xok=3;
    
    if (y==1 || y==3 || y==5 || y==7 || y==8 || y==10 ||y==12) yok=1;
    if (y==4 || y==6 || y==9 || y==11) yok=2;
    if (y==2) yok=3;
    
    if (xok == yok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
    
    
}