#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 10101010

int main()
{
    int w,h,n;
    cin >> w >> h >> n;

    vector<int> x(n),y(n),a(n);

    rep(i,n){
        cin >> x[i] >> y[i] >> a[i];
    }
    int min_x,max_x,min_y,max_y;
    min_x=min_y=0;max_x=w;max_y=h;
    rep(i,n){
        if(a[i]==1){
            if(min_x<x[i]){
                min_x=x[i];
            }
        }else if(a[i]==2){
            if(max_x>x[i]){
                max_x=x[i];
            }
        }else if(a[i]==3){
            if(min_y<y[i]){
                min_y=y[i];
            }
        }else{
            if(max_y>y[i]){
                max_y=y[i];
            }
        }
    }
    int len_x=max_x-min_x;
    int len_y=max_y-min_y;
    if(len_x>=0&&len_y>=0){
        cout << len_x*len_y << endl;
    }else{
        cout << 0 << endl;
    }

}