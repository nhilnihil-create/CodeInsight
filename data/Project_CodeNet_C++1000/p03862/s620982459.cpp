#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    long N, x;
    cin>>N>>x;
    vl a(N);
    REP(i, 0, N){
        cin >> a[i];
    }
    long ans = 0;
    REP(i, 0, N-1){
        if(a[i] + a[i+1] > x){
            ans += a[i] + a[i+1] -x;
            if(a[i+1] < a[i] + a[i+1] -x){
                a[i+1]= 0;
                a[i] -= ans - a[i+1]; 
            }else{
                a[i+1] -= a[i] + a[i+1] -x;
            }
        }
    }
    cout << ans << endl;
}