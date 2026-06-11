#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    pair<int, int>  p[n];
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        p[i] = make_pair(a,b);
    }
    sort(p, p+n);
    cout << (p[n-1].first) + (p[n-1].second) << endl;
    return 0;
}