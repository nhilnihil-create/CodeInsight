#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;


bool mp[110][110];
int main(){

    rep(i,110){
        rep(j,110){
            mp[i][j] = true;
        }
    }
    int w,h,n;
    cin >> w >> h >> n;
    int x,y,a;
    rep(i,n){
        cin >> x >> y >> a;
        if(a == 1){
            rep(i,h){
                rep(j,x){
                    mp[i][j] = false;
                }
            }
        }else if(a == 2){
            rep(i,h){
                reps(j,x,w){
                    mp[i][j] = false;
                }
            }
        }else if(a == 3){
            rep(i,y){
                rep(j,w){
                    mp[i][j] = false;
                }
            }
        }else{
            reps(i,y,h){
                rep(j,w){
                    mp[i][j] = false;
                }
            }
        }
    }

    int cnt = 0;
    rep(i,h){
        rep(j,w){
            if(mp[i][j]){
                //cout << " W";
                cnt++;
            }
            else{
                //cout << " B";
            }
        }
        //cout << endl;
    }
    cout << cnt << endl;
    return 0;
}