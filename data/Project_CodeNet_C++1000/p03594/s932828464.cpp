#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string col = "RGBY";
    int h,w,d;
    cin>>h>>w>>d;
    if(d%2 == 1){
        rep(i,0,h){
            rep(j,0,w){
                cout<<col[(i+j)%2];
            }
            cout<<"\n";
        }
    }
    else{
        int k = d/2;
        vector<vector<int> > v(h,vector<int>(w));
        auto dist = [&](int x, int y, int a, int b){ return abs(x-a) + abs(y-b);};
        auto at = [&](int x, int y, int c){
            rep(i,x-k-2,x+k+2) rep(j,y-k-2,y+k+2){
                if(i>=0 && i<h && j>=0 && j<w){
                    if(dist(i,j,x,y) < k || dist(i,j,x,y+1) < k){
                        v[i][j] = c;
                    }
                }
            }
        };
        rep(t,0,4){
            int x=0,y=0;
            if(t%2 ==  1) x = k, y = k;
            if(t > 1)  x += d;
            rep(i,-2*(h+w+10),2*(h+w+10)) rep(j,-2*(h+w+10),2*(h+w+10)){
                if(i%d == 0 && j%(2*d) == 0){
                    at(x+i,y+j+(d*(((i/d)%2+1)%2)),t+1);
                }
            }
        }
        rep(i,0,h){
            rep(j,0,w){
                cout<<col[v[i][j]-1];
            }
            cout<<"\n";
        }
    }
    return 0;
}
