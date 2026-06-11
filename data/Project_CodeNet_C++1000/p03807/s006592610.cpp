#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    long long int a;
    cin>>n;
    int K=0,G=0;
    for (int i=0;i<n;i++) {
        cin>>a;
        if (a%2==0) {
            G++;
        } else {
            K++;
        }
    }
    if (K%2==1) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }
}