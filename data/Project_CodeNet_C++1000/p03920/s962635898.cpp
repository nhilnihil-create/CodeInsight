#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const ll mod = 1e9 + 7;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main() {
    int N;
    cin>>N;
    int sum=0;
    int ans=0;
    for(int i=1;i<=N;i++){
        sum+=i;
        if(sum>=N) {
            ans=i;
            break;
        }
    }
    int exclude=sum-N;
    for(int i=1;i<=ans;i++){
        if(i==exclude) continue;
        cout<<i<<endl;
    }
    return 0;
}

