#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    ll N;
    cin >> N;
    double A,B;
    cin >> A >> B;
    vector<double> val(N);
    REP(i,N)cin >> val[i];
    sort(ALL(val),greater<>());
    double maximum = val[0];
    double sum = 0;
    REP(i,A){
        sum += val[i];
    }
    double number = 0;
    double numberbefore = 0;
    REP(i,N){
        if(val[i] == val[A-1]){
            number++;
            if(i <= A-1)numberbefore++;
        }
    }
    double answer = 0;
    ll much = 0;
    answer = sum/A;
    if(maximum == val[A-1]){
        double nck = 1;
        REP(i,A){
            nck*=(number-i);
            nck /= i+1;
        }
        // REPS(i,A){
        //     nck/=i;
        // }
        much += nck;
        for(int i = A+1;i<=min(number,B);i++){
            nck*=number-i+1;
            nck/=i;
            much+=nck;
        }
    }else{
        double nck = 1;
        REP(i,numberbefore){
            nck *= number-i;
            nck /= i+1;
        }
        // REPS(i,numberbefore){
        //     nck /= i;
        // }
        much = nck;
    }
    cout << answer << "\n";
    cout << much << "\n";
}