#include<bits/stdc++.h>
#define dbug printf("I am here\n");
#define Fast ios_base::sync_with_stdio(false); cin.tie(0);
#define vs              v.size()
#define sot(v)        sort(v.begin(),v.end())
#define rev(v)        reverse(v.begin(),v.end())
#define ii                pair<int, int>
#define int              long long
#define ull              unsigned long long
#define pb              push_back
#define mpp          make_pair
#define Okay         0
#define pi               3.14159

const int inf = 1e6;
const int cont = 1e18;
const int mod = 1e9+7;
using namespace std;

vector<int>prime;

void seive(){
    bool ar[1010];
    memset(ar, 0, sizeof ar);
    for(int i=4; i*i<1005; i+=2)ar[i] = 1;
    for(int i=3; i<1005; i+=2){
        if(!ar[i]){
            for(int j = i*i; j<=1005; j+=(i+i)){
                ar[j] = true;
            }
        }
    }
    prime.pb(2);
    for(int i=3; i<=1005; i+=2)if(!ar[i])prime.pb(i);
}

void solve(){
  seive();
  int n;
  cin>>n;
  int res = 1;
  for(int i=0; i<prime.size(); i++){
    if(prime[i] > n)break;
    int temp = n;
    int ans = 0;
    while(temp>0){
        temp/=prime[i];
        ans+=temp;
    }
    res *= (ans+1);
    res %=mod;
  }
  cout<<res<<endl;
}

int32_t main() {
    Fast;
    solve();
    return Okay;
}
