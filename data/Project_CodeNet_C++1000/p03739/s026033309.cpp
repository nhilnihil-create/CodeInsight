#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll n, i, a[100001], sum=0, ans=0, ans2=INF;

    cin >> n;

    for(i=1; i<=n; i++){
        cin >> a[i];
    }

    // 正からスタート
    if(a[1]<=0){
        sum = 1;
        ans += abs(a[1]-1);
    }
    else{
        sum = a[1];
    }
    for(i=2; i<=n; i++){
        if(sum>0){
            if(sum+a[i]<0){
                sum += a[i];
            }
            else{
                ans += abs(sum+a[i]+1);
                sum = -1;
            }
        }

        else{
            if(sum+a[i]>0){
                sum += a[i];
            }
            else{
                ans += abs(sum+a[i]-1);
                sum = 1;
            }
        }
    }
    chmin(ans2, ans);

    // 負からスタート
    sum = 0;
    ans = 0;
    if(a[1]>=0){
        sum = -1;
        ans += abs(a[1]+1);
    }
    else{
        sum = a[1];
    }
    for(i=2; i<=n; i++){
        if(sum>0){
            if(sum+a[i]<0){
                sum += a[i];
            }
            else{
                ans += abs(sum+a[i]+1);
                sum = -1;
            }
        }

        else{
            if(sum+a[i]>0){
                sum += a[i];
            }
            else{
                ans += abs(sum+a[i]-1);
                sum = 1;
            }
        }
    }
    chmin(ans2, ans);
    
    cout << ans2 << endl;

    return 0;
}