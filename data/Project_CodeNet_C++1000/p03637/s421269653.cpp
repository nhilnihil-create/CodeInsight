#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin>>N;
    ll a[N];
    rep(i,N){
        cin>>a[i];
    }
    int count0=0,count2=0,count1=0;
    rep(i,N){
        if(a[i]%2!=0){
            count0++;
        }
        else if(a[i]%4==0){
            count2++;
        }
        else if(a[i]%2==0){
            count1++;
        }

}
if(count1>0){
if(count0<=count2){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
}
else{
    if(count0<=count2+1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

    
return 0;
}

