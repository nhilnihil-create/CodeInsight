#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    sort(a,a+2*n);
    int sum=0;
    for(int i=0;i<2*n;i+=2){
        sum+=a[i];
    }
    cout<<sum;
}