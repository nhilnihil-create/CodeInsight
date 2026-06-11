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
    vec A(N);
    vector<bool> s(N - 1, false);
    char c;
    REP(i, N - 1){
        cin >> A[i] >> c;
        if(c == '+') s[i] = true;
    }
    cin >> A[N - 1];

    vec sumA(N + 1);
    sumA[0] = 0;
    REP(i, N) sumA[i + 1] = sumA[i] + A[i];

    int ans = -1 * INF;
    int tmp = A[0];
    REP(i, N - 1){
        if(s[i]){
            tmp += A[i + 1];
        }else{
            tmp -= A[i + 1];
            int tmp2 = tmp;
            FOR(j, i + 1, N - 1){
                if(s[j]){
                    tmp2 -= A[j + 1];
                }else{
                    tmp2 += sumA[N] - sumA[j + 1];
                    break;
                }
            }
            ans = max(ans, tmp2);
        }
    }
    ans = max(ans, tmp);

    cout << ans;
    
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