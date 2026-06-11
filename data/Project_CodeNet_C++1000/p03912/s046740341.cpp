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
    int n,m;
    cin >> n >> m;
    int count[100001] = {};
    rep(i,n){
        int x; cin>>x;
        count[x]++;
    }

    int kisuu[m] = {};
    rep(i,100001){
        if(count[i]%2==1){
            kisuu[i%m]++;
        }
    }

    int ans = 0;

    rep(i,m){
        if(i==0){
            int now = 0;
            int sum = 0;
            while(now*m<100001){
                sum += count[now*m];
                now++;
            }
            ans += sum/2;
        }else if(i*2==m){
            int now = 0;
            int sum = 0;
            while(now*m + i<100001){
                sum += count[now*m+i];
                now++;
            }
            ans += sum/2;
        }else{
            if(m<i*2)break;
            int sum1 = 0;
            int kisuu1 = kisuu[i];
            int now1 = 0; 
            while(now1*m + i<100001){
                sum1 += count[now1*m+i];
                now1++;
            }
            int sum2 = 0;
            int kisuu2 = kisuu[m-i];
            int now2 = 0;
            while(now2*m + (m-i)<100001){
                sum2 += count[now2*m+(m-i)];
                now2++;
            }

            int minikisuu = min(kisuu1,kisuu2);
            ans += minikisuu;
            kisuu1 -= minikisuu;
            kisuu2 -= minikisuu;
            sum1 -= minikisuu;
            sum2 -= minikisuu;
            if(kisuu1>0){
                int mini = min(sum2,kisuu1);
                ans += mini;
                kisuu1 -= mini;
                sum1 -= mini;
                sum2 -= mini;
                sum1 -= kisuu1;
                ans += sum1/2;
                ans += sum2/2;
            }else if(kisuu2>0){
                int mini = min(sum1,kisuu2);
                ans += mini;
                kisuu2 -= mini;
                sum2 -= mini;
                sum1 -= mini;
                sum2 -= kisuu2;
                ans += sum2/2;
                ans += sum1/2;
            }else{
                ans += sum2/2;
                ans += sum1/2; 
            }
        }
        //cout << ans;
    }

    cout << ans << endl;
    return 0;
}
 
 
