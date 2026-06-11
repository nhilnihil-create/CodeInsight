#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
#define PI  3.14159265358979323846264338327950
 
 
int main () {
    int N;
    cin >> N;

    vector<int>a(3*N);
    rep(i,3*N)cin >> a[i];

    sort(a.begin(),a.end());

    long long ans=0;
    for(int i=N; i < 3*N ; i+=2){
        ans += a[i];


    }

    cout << ans << endl;
}
