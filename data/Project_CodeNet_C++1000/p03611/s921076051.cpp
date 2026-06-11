#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
int main(){
    int n; cin >> n;
    vector<int> ar(1000001,0);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        ar[a]++;
        ar[a+2]++;
        ar[a+1]++;
    }
    int ma = 0;
    int ans = -1;
    rep (i,1000001){
        if (ar[i] > ma){
            ma = ar[i];
            ans = i-1;
        }
    }
    cout << ma << endl;
}