#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 2e5 + 5;
int n;
int v[maxn];
bool solve(int x) {
    //cout << x << endl;
    int mid = (n / 2);
    for (int i = 1 ; i <= n / 2 ; i++) {
        if (((v[mid-i] >= x) ^ (v[mid-i+1] >= x)) == 0) {
            //cout << v[mid-i] <<' '<<v[mid-i+1] << endl;
            return v[mid-i] >= x;
        }
        if (((v[mid+i] >= x) ^ (v[mid+i-1] >= x)) == 0) {
            //cout << v[mid+i] <<' '<<v[mid+i-1] << endl;
            return v[mid+i] >= x;
        }
    }
    return v[0] >= x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    n = n * 2 - 1;
    f(n) {
        cin >> v[i];
    }
    int l = 1, r = n;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if (solve(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << '\n';
}