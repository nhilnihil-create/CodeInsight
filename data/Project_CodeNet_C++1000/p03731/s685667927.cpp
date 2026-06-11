#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    long long int T,t;
    cin>>T;
    long long int sum=0;
    long long int start,end;
    for (int i=0;i<n;i++) {
        cin>>t;
        if (i==0) {
            start=t;
            end=T;
        } else {
            if (t<=end) {
                end=t+T;
            } else {
                sum+=end-start;
                start=t;
                end=start+T;
            }
        }
    }
    sum+=end-start;
    cout<<sum<<endl;
}