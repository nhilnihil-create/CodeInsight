#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;
 
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;
 
template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);
 
 
 
signed main(){
 
    string A; cin >> A;
    
    mat alfpos(26, vec(1, -1));
    REP(i, A.size()){
        alfpos[A[i] - 'a'].push_back(i);
    }
 
    vec x(0);
    int pos = INF, alf;
    while(pos >= 0){
        int minv = INF;
        REP(i, 26){
            int p = distance(alfpos[i].begin(), lower_bound(alfpos[i].begin(), alfpos[i].end(), pos)) - 1;
            int v = alfpos[i][p];
            if(v < minv){
                minv = v;
                alf = i;
            }
        }
        pos = minv;
        if(pos >= 0) x.push_back(pos);
    }

    string ans = "";
    ans += (char)('a' + alf);

    REVERSE(x);
    x.push_back(A.size());
    
    FOR(i, 0, x.size() - 1){
        bool used[26];
        fill(used, used + 26, false);
        int j0;
        FOR(j, x[i], x[i + 1]){
            if(A[j] - 'a' == alf){
                j0 = j;
                break;
            }
        }
        FOR(j, j0 + 1, x[i + 1]) used[A[j] - 'a'] = true;
        REP(j, 26){
            if(!used[j]){
                alf = j;
                break;
            }
        }
        ans = ans + (char)('a' + alf);
    }

    
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