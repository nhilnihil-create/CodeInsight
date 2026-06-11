#include<bits/stdc++.h>                                                                                               
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;

int sum[6000050];
signed main(){
    int n;
    cin >> n;
    if(n == 1){ 
        cout << 1 << '\n';
        return 0;
    }   
    reps(i,n / 2 + 1){ 
        sum[i] = sum[i - 1] + i;
    }   

    int low = 0;
    int high = n+1;
    while(high - low > 1){ 
        int mid = (high + low) / 2;
        if(sum[mid] >= n){ 
            high = mid;
        }
        else{
            low = mid;
        }
    }   
    
    int err = sum[high] - n;
    reps(i,high){
        if(i == err) continue;
        cout << i << '\n';
    }   
    return 0;
}
