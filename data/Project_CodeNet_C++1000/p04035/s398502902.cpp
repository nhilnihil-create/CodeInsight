#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l;
    cin >> n >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lst=-1;
    for(int i = 1; i < n; i++) {
        if(a[i-1]+a[i]>=l){
            lst=i;
            break;
        }
    }

    if(lst==-1){
        cout << "Impossible" << "\n";
        return 0;
    }

    cout << "Possible" << "\n";
    for(int i = 1; i < lst; i++) {
        cout << i << "\n";
    }
    for(int i = n-1; i > lst; i--) {
        cout << i << "\n";
    }
    cout << lst << "\n";

    return 0;
}