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
const int mod = 998244353;
ll n, k, v[51];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    n = 50;
    for (int i = 0 ; i < 50 ; i++) {
        v[i] = 49 + k / 50;
    }
    k %= 50;
    for (int i = 0 ; i < k ; i++) {
        v[i] += n + 1;
        for (int j = 0 ; j < n ; j++) {
            v[j]--;
        }
    }
    cout << n << '\n';
    f (n) {
        cout << v[i] << ' ' ;
    }
    cout << '\n';
}