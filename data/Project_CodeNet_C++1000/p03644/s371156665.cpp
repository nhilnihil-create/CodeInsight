#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int tmp=1;
    int cnt=0;
    while(tmp<=n){
        tmp=2*tmp;
        cnt++;
    }
    cout<<pow(2,(cnt-1))<<endl;
}