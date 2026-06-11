#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int left = max(a,c);
    int right = min(b,d);
    cout << max(right - left, 0) << endl;
    return 0;
}