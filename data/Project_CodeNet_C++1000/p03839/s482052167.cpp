#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iostream>
#include <queue>
#include <math.h>
#include <bits/stdc++.h>
#include <queue>
#include <map>

using namespace std;

#define INF (1ll<<60)
#define INFint (1<<30)
#define MOD 1000000007
#define BOUND 27182818284

typedef long long ll;
typedef long long int lli;
// typedef pair<ll,ll> P;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

template<class T>
bool umax(T &a, const T &b){
    if (a<b) {
        a=b; return true;
    }
    return false;
}

template<class T>
bool umin(T &a, const T &b) {
    if (b<a) {
        a=b; return true;
    }
    return false;
}

// gcd
template<typename T>
T gcd(T a, T b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

// gcd array
int findGCD(int arr[], int n){
    int result = arr[0];
    for (int i=1; i < n; i++)
        result = gcd(arr[i], result);
    return result;
}

template<typename T>
T lcm( T m, T n ){
    // 引数に0がある場合は0を返す
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;
    return ((m/gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}


int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};

// v.front() = -BOUND;
// v.back() = BOUND;

//struct edge{
//    int cost, to;
//
//    edge(int in_cost, int in_to){
//        cost=in_cost;
//        to=in_to;
//    }
//    bool operator<(const edge &a) const
//    {
//        return cost > a.cost;
//    }
//};

int A[100010];
ll plus_sum[100010];
ll Ksum[100010];
int main() {
    int N,K; cin>>N>>K;

    plus_sum[0]=0LL;
    rep(i,N){
        cin >> A[i];
        if(A[i]>0){
            plus_sum[i+1]+=A[i]+plus_sum[i];
        }else{
            plus_sum[i+1]=plus_sum[i];
        }
    }

    ll sum=0LL;
    for(int i=0; i<K; i++){
        sum+=A[i];
    }
    Ksum[0]=sum;
    for(int i=0; i<=N-K; i++){
        Ksum[i+1]=Ksum[i]-A[i]+A[i+K];
    }

    ll maximum=0LL;
    for(int i=0; i<=N-K; i++){
        maximum=max(maximum, plus_sum[i]+max(0LL,Ksum[i])+plus_sum[N]-plus_sum[i+K]);
    }

    cout << maximum << endl;

    return 0;
}
