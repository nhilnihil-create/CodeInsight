#include<bits/stdc++.h>

#define FOR(i, a, b) for(int(i)=(a);(i)<(b);(i)++)
#define REP(i, n) FOR((i), 0, (n))

#define RFOR(i, b, a) for(int(i)=(b); (i)>=(a); (i)--)
#define RREP(i, n) FOR((i), (n), 0)

#define pb push_back
#define mp make_pair

using namespace std;

const bool DEBUG=true;

template<class T>
void debug(T head){
    cerr<<head<<endl;
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cerr<<head<<" ";
        debug(body...);
    }
}

const int INF=INT_MAX/4;
const int MOD=1000000007;
const double EPS=1e-14;

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(10);

    int N, K;
    cin>>N>>K;
    vector<long> a(N), b(N);
    cin>>a[0];
    if(a[0]>0){
        b[0] = a[0];
    }else{
        b[0] = 0;
    }
    for(int i=1; i<N; ++i){
        cin>>a[i];
        if(a[i]>0){
            b[i] = b[i-1] + a[i];
        }else{
            b[i] = b[i-1];
        }
    }

    long sum_K_length = 0;
    for(int i=0; i<K; ++i){
        sum_K_length += a[i];
    }
    long ans = max(b[N-1] - b[K-1] + sum_K_length, b[N-1] - b[K-1]);
    for(int i=K; i<N; ++i){
        sum_K_length = sum_K_length - a[i-K] + a[i];
        ans = max(ans, max(b[i-K] + sum_K_length + b[N-1] - b[i], b[i-K] + b[N-1] - b[i]));
    }

    cout<<ans<<endl;

    return 0;
}
