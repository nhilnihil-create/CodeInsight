#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int>s(n);
    rep(i,n)cin >> s[i];
    sort(all(s));
    int sum = 0;
    rep(i,n)sum += s[i];
    if(sum%10 != 0){
        cout << sum << endl;
        return 0;
    }
    rep(i,n){
        if(s[i]%10 != 0){
            cout << sum-s[i] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}