#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    int f = 0;
    for (auto &i : v) {
        cin >> i;
    }
    for (int i = 1 ; i < v.size() ; i++) {
        if (v[i] + v[i-1] >= k) {
            f = i;
            break;
        }
    }
    if (!f) {
        cout << "Impossible\n";
        exit(0);
    }
    cout << "Possible\n";
    f1(f-1){
        cout << i <<'\n';
    }
    for (int i = n - 1 ; i >= f ; i--) {
        cout << i <<'\n';
    }
}
    

