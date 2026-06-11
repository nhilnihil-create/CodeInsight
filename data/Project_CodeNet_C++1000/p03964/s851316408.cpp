#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long  t1,a1,t2,a2;
    cin>>t1>>a1;
    for(int i=1;i<n;i++){
        cin>>t2>>a2;
        long long tmp1=max(((t1+t2-1)/t2),((a1+a2-1)/a2));
        t1=tmp1*t2;
        a1=tmp1*a2;
    }
    cout<<a1+t1<<endl;
    return 0;
}