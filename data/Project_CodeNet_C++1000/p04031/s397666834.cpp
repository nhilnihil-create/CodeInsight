#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i=0; i < (n); ++i)
using ll = long long ;
using namespace std;
const int INF = 1001001001;

int main() {

    int n ;
    cin >> n  ;
    vector<int> a(n) ;
    int sum = 0 ;
    rep(i,n){
        cin >> a[i] ;
        sum+=a[i] ;
    }
    sort(a.begin(),a.end()) ;
    int mean = sum/n ;
    int ans = 0 ;
    int ans2 = 0 ;
    rep(i,n){
        ans+=(a[i]-mean)*(a[i]-mean) ;
    }

    rep(i,n){
        ans2+=(a[i]-(mean+1))*(a[i]-(mean+1)) ;
    }

    cout << min(ans,ans2) << endl ;

    return 0 ;
}
