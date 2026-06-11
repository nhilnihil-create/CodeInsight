#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;
int a[1005];
int dp[1005][1005];
int sum[1005][1005];
int p[1005][1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<int>st;
    int gg = 0;
    for (auto i:s) {
        if (i == 'S') {
            st.push(1);
        }
        else {
            if (st.size()) {
                st.pop();
            }
            else {
                gg++;
            }
        }
    }
    cout << gg + st.size() << '\n';
}
