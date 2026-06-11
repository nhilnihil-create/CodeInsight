#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        int A;
        cin >> A;
        a[i] = A;
    }
    int f = 1, cnt = 0;
    int pre = 1;
    vector<int> C(n+1);
    C[1]++;
    while(true){
        //cout << f << " " << pre << endl;
        f = a[f];
        C[f]++;
        if(C[f] > 1){
            cout << -1 << endl;
            return 0;
        }
        if(pre == f) break;
        cnt++;
        pre = f;
        if(f == 2) break;
    }
    cout << cnt << endl;
    return 0;
}