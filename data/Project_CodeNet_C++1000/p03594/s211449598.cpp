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
    int h,w,d;
    cin >> h >> w >> d;
    
    if(d%2==1){
        rep(i,h){
            rep(j,w){
                if((i+j)%2==0){
                    cout << 'R';
                }else{
                    cout << 'B';
                }
            }
            cout << endl;
        }
    }else{
        char c[d*2][d*2];
        rep(i,d){
            rep(j,d){
                if(j < d/2) c[i][j] = 'G';
                else c[i][j] = 'Y';
            }
        }
        drep(i,d){
            int l = d - 1 - i;
            int r = i;
            srep(j,l,r+1)c[i][j] = 'R';
            l = i + 1;
            r = d - 2 - i;
            srep(j,l,r+1) c[i][j] = 'B';
        }
        rep(i,d){
            srep(j,d,d*2){
                if(c[i][j-d] == 'G') c[i][j] = 'Y';
                if(c[i][j-d] == 'Y') c[i][j] = 'G';
                if(c[i][j-d] == 'B') c[i][j] = 'R';
                if(c[i][j-d] == 'R') c[i][j] = 'B';
            }
        }
        srep(i,d,d*2){
            rep(j,d*2){
                if(c[i-d][j] == 'G') c[i][j] = 'Y';
                if(c[i-d][j] == 'Y') c[i][j] = 'G';
                if(c[i-d][j] == 'B') c[i][j] = 'R';
                if(c[i-d][j] == 'R') c[i][j] = 'B';
            }
        }


        char ans[h][w];
        rep(i,h){
            rep(j,w){
                cout << c[i%(d*2)][j%(d*2)];
            }
            cout << endl;
        }
    }


    return 0;
}
 
 
