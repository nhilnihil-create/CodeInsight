#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int> A(n+1);
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        A[i] = a;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int tmp = A[i];
        if(i == A[tmp]) cnt++;
    }
    cout << cnt/2 << endl;
    return 0;
}