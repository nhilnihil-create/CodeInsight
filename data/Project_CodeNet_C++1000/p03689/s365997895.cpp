#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
    int H,W,h,w;
    cin >> H >> W >> h >> w;

    if(H%h==0 && W%w==0){
        cout << "No" << endl;
        return 0;
    }

    ll a[H][W];
    ll sum = 0;
    rep(i,H){
        rep(j,W){
            if((i+1)%h==0 && (j+1)%w==0){
                a[i][j] = -100000000;
            }else if(i%h==0 && j%w==0){
                a[i][j] = 99999999;
            }else{
                a[i][j] = 0;
            }
            sum += a[i][j];
        }
    }

    if(sum<=0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        rep(i,H){
            rep(j,W){
                if(j==W-1){
                    cout << a[i][j] << endl;
                }else{
                    cout << a[i][j] << ' ';
                }
            }
        }
    }


    return 0;
}
 
 
