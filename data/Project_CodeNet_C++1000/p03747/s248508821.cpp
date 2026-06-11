#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};

int N;
ll L, T;
vector<ll> X;
vector<int> W;

int main(){
    cin >> N >> L >> T;
    X.resize(N);  W.resize(N);
    rep(i,N) cin >> X[i] >> W[i];
//-------------------------------------------
    vector<ll> tmp(N);
    rep(i,N){
        if(W[i]==1) tmp[i] = (X[i]+T)%L;
        else tmp[i] = ((X[i]-T)%L+L)%L; //tmp[i] = (X[i]-T)%L;
    }

    int cnt = 0;
    rep(i,N){
        if(W[i]==1) cnt += (X[i]+T)/L;
        else{
            //if(T > X[i])
              //  cnt -= 1+(T-X[i])/L;
            cnt += (X[i]-T)/L;
            //if((X[i]-T)%L<0) tmp[i]+=L, cnt--;
            if((X[i]-T)%L<0) cnt--;
        }
    }
    int flag = (cnt%N+N)%N;
    sort(tmp.begin(), tmp.end());
//-------------------------------------------
    for(int i = flag; i < N; i++) cout << tmp[i] << endl;
    for(int i = 0; i < flag; i++) cout << tmp[i] << endl;
}