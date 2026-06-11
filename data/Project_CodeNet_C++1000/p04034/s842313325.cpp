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

int main(){
    int n,m;
    cin >> n >> m;
    
    vector<bool> vec(n,false);
    vector<int> ball(n,1);
    int x,y;

    vec[0] = true;
    rep(i,m){
        cin >> x >> y;
        x--; y--;
        if(vec[x]){        
            vec[y] = true;
        }
        if(vec[x] && ball[x] == 1){
            vec[x] = false;
        }
        ball[x]--;
        ball[y]++;
        
    }
    int cnt = 0;
    rep(i,n){
        if(vec[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}