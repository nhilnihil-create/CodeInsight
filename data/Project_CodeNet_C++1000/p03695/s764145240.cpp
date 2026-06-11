#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    vector<int>vec(8);
    int b = 0;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        if(x < 400){
            vec.at(0)++;
        }else if(x < 800){
            vec.at(1)++;
        }else if(x < 1200){
            vec.at(2)++;
        }else if(x < 1600){
            vec.at(3)++;
        }else if(x < 2000){
            vec.at(4)++;
        }else if(x < 2400){
            vec.at(5)++;
        }else if(x < 2800){
            vec.at(6)++;
        }else if(x < 3200){
            vec.at(7)++;
        }else{
            b++;
        }
    }
    
    int cnt = 0;
    for(int i = 0;i < 8;i++){
        if(vec.at(i) > 0){
            cnt++;
        }
    }
    
    int ans1 = cnt;
    int ans2 = cnt+b;
    ans1 = max(1,ans1);
    cout<< ans1 << " " << ans2;
    
}


