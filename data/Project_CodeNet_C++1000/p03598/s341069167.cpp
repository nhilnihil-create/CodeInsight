#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
    int n,k;
    cin >> n >> k;
    VI x(n);
    rep(i,n)cin >> x.at(i);
    int sum=0;
    rep(i,n){
        sum+=min(x[i],k-x[i]);
    }
    cout << sum*2 << endl;
}