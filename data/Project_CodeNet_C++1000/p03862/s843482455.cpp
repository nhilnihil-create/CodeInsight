#include <iostream>
using namespace std;

int main(){
    int n;
    long int x;
    cin>>n>>x;
    long int a[n];
    long int n_t = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>x){
            n_t += a[i]-x;
            a[i] = x;
        }
        if(a[i]+a[i+1]>x){
            n_t += a[i]+a[i+1]-x;
            a[i+1] -= a[i]+a[i+1]-x;
        }
    }
    cout<<n_t<<endl;
    return 0;
}