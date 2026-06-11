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
    int n,c,k;
    cin >> n >> c >> k;
    vi vec(n);
    rep(i,n) cin >> vec[i];
    sort(vec.begin(),vec.end());
int cnt = 0;
    rep(i,n){
        rep(j,c){
            if(vec[i] + k < vec[i+j+1]){
                cnt++;
                i += (j);
                break;
            }
            if(j == c-1){
                i += c-1;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
