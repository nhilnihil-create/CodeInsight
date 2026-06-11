#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
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
    N++;

    vec s(0);
    while(N > 0){
        int b = N % 2;
        s.push_back(b);
        N = (N - b) / 2;
    }

    int n = s.size();
    vec ans1(n - 1), ans2(0);
    REP(i, n - 1) ans1[i] = i + 1;
    REP(i, n - 1){
        if(s[i] == 1){
            ans1.insert(ans1.begin() + n - 1 - i, 51 + i);
            ans2.push_back(51 + i);
        }
    }
    REP(i, n - 1) ans2.push_back(i + 1);

    cout << ans1.size() + ans2.size() << endl;
    REP(i, ans1.size()) cout << ans1[i] << " ";
    REP(i, ans2.size()) cout << ans2[i] << " ";

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