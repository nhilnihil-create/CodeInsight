#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> l(n*2);
    rep(i,2*n){
        cin >> l[i];
    }
    int sum = 0;
    sort(l.begin(),l.end());
    rep(i,2*n){
        if(i%2==0) sum += l[i];
    }
    cout << sum << endl;
    return 0;
}
