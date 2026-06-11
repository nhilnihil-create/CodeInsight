#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a,b;
    cin>>n;
    long long int A[n];
    long long int B[n];
    for (int i=0;i<n;i++) {
        cin>>a>>b;
        A[i]=a;
        B[i]=b;
    }
    sort(A,A+n);
    sort(B,B+n,greater<long long int>());
    long long int sum=0;
    for (int i=0;i<n;i++) {
        if (i==0) {
            sum+=A[i];
        } else {
            sum+=A[i]-A[i-1];
        }
    }
    sum+=B[n-1];
    cout<<sum<<endl;
}