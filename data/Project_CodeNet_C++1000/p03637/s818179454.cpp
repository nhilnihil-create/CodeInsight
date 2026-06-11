#include<iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int a[100000]={0};
    for(int i(0);i<n;i++){
        cin>>a[i];
    }
    int two(0);
    int four(0);
    for(int i(0);i<n;i++){
        if(a[i]%4==0)four++;
        else if(a[i]%2==0)two++;
    }
    if(two>=2){
        int left = n-two;
        int div = left / 2;
        int mod = left % 2;
        if(mod>0)div++;
        if(four>=div)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else{
        int div = n / 2;
        if(four>=div)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}