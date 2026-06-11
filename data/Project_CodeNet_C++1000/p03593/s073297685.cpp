#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long lint;
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(lint (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
const lint MOD =1000000007;
const lint MAX = 1000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
typedef map<lint,lint> M;
 
lint fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() 
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
}
   long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
    lint lcm(lint a,lint b){
        return a/__gcd(a,b)*b;
    }
     lint gcd(lint a,lint b){
        return __gcd(a,b);
    } 
    
 
     lint a[26];
  int main(){
    int h,w;
    cin>>h>>w;
    rep(i,h*w){
        char x;
        cin>>x;
        lint c=x-'a';
        a[c]++;
    }
    priority_queue<lint> n;
    rep(i,26){
    if(a[i]!=0) n.emplace(a[i]);
    }
    deque<P> que;
    if(h%2==0&&w%2==0)que.push_back({4,h*w/4});
    else if(h%2==1&&w%2==1){
        int f=(h-1)*(w-1)/4;
          if(f)que.push_back({4,f});
            f=h*w-f*4-1;
            f/=2;
           if(f)que.push_back({2,f});
           que.push_back({1,1});
    }else {
        if(h%2==1)swap(h,w);
        int g=h*(w-1)/4;
        if(g)que.push_back({4,g});
        g=h*w-4*g;
        g/=2;
         if(g)que.push_back({2,g});
    }
    lint count=0;
 
    while(!n.empty()||!que.empty()){
            lint x=n.top();
            n.pop();
            lint y,z;
            tie(y,z)=que.front();
            que.pop_front();
            lint b=x/y;
            if(b<z){
                que.push_front({y,z-b});
                x-=b*y;
                if(x)n.emplace(x);
            }else{
                 x-=z*y;
                 if(x)n.emplace(x);
            }

            count++;
            if(count>20000){
                cout<<"No"<<endl;
                return 0;
            }
    }
    cout<<"Yes"<<endl;

     }
  
      
      
    

  
          
  