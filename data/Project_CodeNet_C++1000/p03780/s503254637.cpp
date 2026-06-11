#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}


int main() {
    int n,k;
    cin >> n >> k;
    int a[n];
    int count = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i]<k)count++;
    }
    sort(a,a+n);
    int b[count];
    rep(i,count){
        b[count-1-i] = a[i];
    }
    
    rep(i,count){
        //cout << b[i] << ' ';
    }
    cout << endl;
    
    //cout << count;

    int last = count;
    //cout << last << endl;

    int dp[k] = {};
    int dp2[k] = {};

    rep(i,count){
        rep(j,k){
            dp2[j] = dp[j];
        }
        rep(j,k){
            if(j==b[i]){
                dp2[j] = 1;
            }
            if(dp[j]>0){
                //cout << j << ' ';
                if(j+b[i]>=k){
                    last = count - 1 - i;
                }else{
                    dp2[j+b[i]] = 1;
                }
            }
        }
        rep(j,k){
            dp[j] = dp2[j];
        }
    }


    cout << last << endl;
    return 0;
}
 
 
