#include <bits/stdc++.h>
using namespace std;
const int m=2e5+1;
long long a[m],b[m];
main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    double press=0ll;
    for(int i=n-1;i>=0;i--){
        if(a[i])
            press = b[i]*ceil((a[i]+press)/b[i])-a[i];
    }
    cout << fixed << setprecision(0) << press << endl;
}

///??????? f u 
/* why tf zero is a multiple ?? */