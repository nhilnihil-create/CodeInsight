#include<iostream>
using namespace std;

int main(){
    /*奇数の数が2で割り切れる場合は、OK*/
    int n;
    cin>>n;
    int a;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2!=0)cnt++;
    }
    if(cnt%2==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}