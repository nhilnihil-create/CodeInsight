#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    ll N,sum = 0;
    cin >> N;
    vector<ll> A(N),D;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    rep(i,N){
        if(i == N-1) D.push_back(A[0] - A[i]);
        else D.push_back(A[i+1] - A[i]);
    }
    if((2 * sum) % (N * (N+1)) != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll U = (2*sum) / (N * (N+1)),cnt = 0;
    rep(i,N){
        if(U - D[i] < 0){
            cout << "NO" << endl;
            return 0;
        }
        if((U - D[i]) % N == 0){
            cnt += (U - D[i]) / N;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    /*if(cnt != U){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }*/
    cout << "YES" << endl;
}
