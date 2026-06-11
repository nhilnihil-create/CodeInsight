#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define dump(x) cout << #x << " = " << (x) << endl
#define chk() cout << "now" << endl;
#define SORT(c) sort((c).begin(), (c).end())
#define SORTG(c) sort((c).begin(), (c).end(), greater<int>());
#define fi first
#define se second
  
typedef pair<int,int> P;
typedef vector<int> vi;

int N;
vi a;

signed main() {
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int> q2;

    cin >> N;
    int sum1 = 0, sum2 = 0;
    rep(i, 0, 3*N) {
        int A; cin >> A;
        a.pb(A);
        if(i <= N-1) {
            q1.push(A);
            sum1 += A;
        }
        if(i >= 2*N) {
            q2.push(A);
            sum2 += A;
        }
    }

    
     vi s1, s2;
     s1.pb(sum1);
     s2.pb(sum2);

     rep(k, 0, N) {
         q1.push(a[N+k]);
         sum1 += a[N+k];
         sum1 -= q1.top();
         q1.pop();
         s1.pb(sum1);

         q2.push(a[2*N-1-k]);
         sum2 += a[2*N-1-k];
         sum2 -= q2.top();
         q2.pop();
         s2.pb(sum2);

    }

     int max;
     rep(i, 0, N+1) {
         int ret = s1[i] - s2[N-i];
         if(i == 0) max = ret;
         if(ret > max) max = ret;
     }

     cout << max << endl;
     return 0;
}





    

    
