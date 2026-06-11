#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <long long> a(3*n);
    for(long long i = 0; i < 3*n; i++)cin>>a[i];
    sort(a.begin(),a.end());
    #if 0
    for(long long i = 0; i < 3*n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    #endif
    long long ans = 0;
    //ans = a[2] + a[4];
    //n=2, 1 2 | 3 4 | 5 6 (3,5)
    //n=3, 1 2 3 | 4 5 6 | 7 8 9 (4,6,8)
    //n=4, 1 2 3 4 | 5 6 7 8 | 9 10 11 12 (5,7,9,11)
    for(long long i = n; i < 3*n; i+=2){
        ans+=a[i];
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}