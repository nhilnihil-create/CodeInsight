#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n;
    cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll out,cnt,sum;
    cnt = 0;
    bool odd  = true;
    sum = 0;
    rep(i,n){
        bool j_odd = true;
        if(i%2==0) j_odd = false;
        sum+=a[i];
        if(j_odd){
            if(sum>=0){
                cnt += sum + 1;
                sum = -1;
            }
        }else{
            if(sum<=0){
                cnt += -sum + 1;
                sum = 1;            
            }
        }
    }
    out = cnt;
    cnt = 0;
    sum = 0;
    rep(i,n){
        bool j_odd = true;
        if(i%2==1) j_odd = false;
        sum+=a[i];
        if(j_odd){
            if(sum>=0){
                cnt += sum + 1;
                sum = -1;
            }
        }else{
            if(sum<=0){
                cnt += -sum + 1;
                sum = 1;            
            }
        }
    }
    out = min(out,cnt);
    cout << out << endl;
    return 0;
}