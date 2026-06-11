#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define fi first
#define se second
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr ll INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int> > Q,P;
    int N;cin >> N;
    int A[N];
    REP(i,N){
        cin >> A[i];
        if(i % 2 == 0) Q.push(A[i]);
        else P.push(A[i]);
    }
    int cnt = 0,X,Y;
    bool flag = 0;
    vector<int> ans;
    while(!P.empty() || !Q.empty()){
        if(!Q.empty()) X = Q.top();//偶数番目
        else X = INF;
        if(!P.empty()) Y = P.top();//奇数番目
        else Y = INF;

        if(ans.size() % 2 == 0 && X < Y){
            ans.pb(X);
            Q.pop();
        }
        else if(ans.size() % 2 == 0 && X > Y){
            if(flag){
                cnt++;
                flag = 0;
            }
            else flag = 1;
            ans.pb(Y);
            P.pop();
        }
        else if(ans.size() % 2 == 1 && X > Y){
            ans.pb(Y);
            P.pop();
        }
        else if(ans.size() % 2 == 1 && X < Y){
            if(flag){
                cnt++;
                flag = 0;
            }
            else flag = 1;
            ans.pb(X);
            Q.pop();
        }
    }
    cout << cnt << endl;
}
