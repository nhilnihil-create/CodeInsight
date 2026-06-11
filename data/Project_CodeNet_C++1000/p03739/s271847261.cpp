#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n;
    cin >> n;
    int a[n];
    REP(i,n)cin >> a[i];
    //a[0]を正の数とした場合
    ll count = 0,ans = 0;
    REP(i,n){
        ans += a[i];
        if(i%2==0){
            if(ans>0)continue;
            else {
                count+=abs(ans)+1;
                ans = 1;
            }
        }
        else{
            if(ans<0)continue;
            else {
                count+=abs(ans)+1;
                ans = -1;
            }
        }
    }
    //a[0]を負の数とした場合
    ll count1 = 0,ans1 = 0;
    REP(i,n){
        ans1 += a[i];
        if(i%2!=0){
            if(ans1>0)continue;
            else {
                count1+=abs(ans1)+1;
                ans1 = 1;
            }
        }
        else{
            if(ans1<0)continue;
            else {
                count1+=abs(ans1)+1;
                ans1 = -1;
            }
        }
    }
    COUT(min(count,count1));
    return 0;
}