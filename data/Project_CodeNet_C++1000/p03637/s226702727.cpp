#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int ocnt=0,fcnt=0,tcnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2!=0)ocnt++;
        if(a[i]%4==2)tcnt++;
        if(a[i]%4==0)fcnt++;
    }
    if(tcnt==0&&ocnt<=fcnt+1)cout<<"Yes"<<endl;
    else if(tcnt!=0&&ocnt<=fcnt)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}