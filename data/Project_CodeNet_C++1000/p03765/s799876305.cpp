#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

string s, t;
int sum[2][2][100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for(int i=0;i<n;i++){
        sum[0][0][i+1] = sum[0][0][i] + (s[i]=='A');
        sum[0][1][i+1] = sum[0][1][i] + (s[i]=='B');
    }
    for(int i=0;i<m;i++){
        sum[1][0][i+1] = sum[1][0][i] + (t[i]=='A');
        sum[1][1][i+1] = sum[1][1][i] + (t[i]=='B');   
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int A = (sum[0][0][b] - sum[0][0][a-1]) + 2*(sum[0][1][b] - sum[0][1][a-1]);
        int B = (sum[1][0][d] - sum[1][0][c-1]) + 2*(sum[1][1][d] - sum[1][1][c-1]);
        if(A%3 == B%3) printf("YES\n");
        else printf("NO\n");
    }
}