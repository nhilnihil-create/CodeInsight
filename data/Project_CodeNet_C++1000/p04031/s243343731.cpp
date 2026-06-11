#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    long long tmp=2e18;
    int ans;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=-100;i<=100;i++){
        long long sum=0;
        for(int j=0;j<n;j++){
            sum+=(a[j]-i)*(a[j]-i);
        }
        if(tmp>sum){
            tmp=sum;
            ans=i;
        }
    }
    cout<<tmp<<endl;
    return 0;
}