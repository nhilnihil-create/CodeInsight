#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, a[200100], i, b[200100], pre, back;
    cin >> n;
    pre=0;back=n-1;
    for(i=0;i<n;i++){
        cin >> a[i];
        }
        reverse(a, a+n);
    for(i=0;i<n;i++){
        if(i%2==0){
            b[pre]=a[i];
            pre++;
        }
        else {
            b[back]=a[i];
            back--;
        }
    }

    for(i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout <<endl;

    return 0;
}