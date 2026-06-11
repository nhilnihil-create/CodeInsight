#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PLL> VP;
typedef vector<ll> VLL;
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
#define repd(i,n) for (ll i=n-1; i>=0; i--)
#define rept(i,m,n) for(ll i=m; i<n; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PF push_front
#define PB push_back
#define SORT(V) sort((V).begin(), (V).end())
#define RVERSE(V) reverse((V).begin(), (V).end())
#define paired make_pair
#define PRINT(V) for(auto v : (V)) cout << v << " "

int main()
{
    ll N; cin >> N;
    VLL A(N), B(N);
    rep(i,N){
        cin >> A.at(i) >> B.at(i);
    }
    VI count(N);
    ll plus=0;
    repd(i,N){
        A.at(i)+=plus;
        if(A.at(i)==0){
            continue;
        }
        if(A.at(i)<B.at(i)){
            count.at(i)=B.at(i)-A.at(i);
            plus+=B.at(i)-A.at(i);
            continue;
        }
        if(A.at(i)%B.at(i)==0){
            continue;
        }
        else{
            count.at(i)=B.at(i)-(A.at(i)%B.at(i));
            plus+=B.at(i)-(A.at(i)%B.at(i));
        }
    }
    ll sum=0;
    rep(i,N){
        sum+=count.at(i);
    }
    cout << sum << endl;
}