#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    long long count=0;
    for(int i=n-1;i>=0;i--){
        a[i]+=count;
        if(a[i]%b[i]!=0) count+=b[i]-a[i]%b[i];
    }
    cout << count << endl;
}