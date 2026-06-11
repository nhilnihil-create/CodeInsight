#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,l,n) for(int i=(l);i<(n);i++)


int main(){
    int N,K;
    ll money=2e10;
    cin >> N >> K;
    int height[N];
    rep(i,N) cin >> height[i];
    for(int bit = 0;bit < 1 << N;bit++){
        int max_b = height[0];
        int count = 1;
        ll temp = 0;
        for(int build = 1;build < N;build++){
            if(max_b < height[build]) {
                count++;
                max_b = height[build];
            }
            else{
                if(bit & (1 << build)){
                    temp += max_b-height[build]+1;
                    count++;
                    max_b++;
                } 
            }
        }
        if(count >= K) money = min(money,temp);
    }
    cout << money << endl;
    return 0;
}
