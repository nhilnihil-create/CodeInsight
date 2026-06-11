#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int N; cin >> N;
    vec a(N); readvec(a);

    map<int, int> index, num;
    REP(i, N){
        if(num[a[i]] == 0) index[a[i]] = i;
        num[a[i]]++;
    }

    vector<Pii> P;
    for(auto p: num) P.push_back(Pii(p.first, p.second));
    SORT(P);
    REVERSE(P);
    P.push_back(Pii(0, INF));

    vec ans(N, 0);
    int m = INF;
    int n = 0;
    REP(i, P.size() - 1){
        m = min(m, index[P[i].first]);
        n += P[i].second;
        ans[m] += n * (P[i].first - P[i + 1].first);
    }

    REP(i, N) cout << ans[i] << endl;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}