// いっしょ
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int avg=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        avg+=a[i];
    }
    avg/=n;
    int b=0;
    int c=0;
    for(int i=0; i<n; i++){
        b+=(a[i]-avg)*(a[i]-avg);
        c+=(a[i]-avg-1)*(a[i]-avg-1);
    }
    cout << min(b, c) << endl;
    return 0;
}