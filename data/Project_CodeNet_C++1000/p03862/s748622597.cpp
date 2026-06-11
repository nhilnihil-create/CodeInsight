#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long int n,x;
    cin>>n>>x;
    vector<long long int>a(n);
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int count=0;
    for(long long int i=0;i<n-1;i++)
    {
        if(a[i]+a[i+1]>=x){
            if(a[i]>x){
                long long int temp=a[i];
                a[i]=x;
                count+=temp-a[i];
                count+=a[i+1];
                a[i+1]=0;
            }
            else{
                long long int temp=a[i+1];
                a[i+1]=x-a[i];
                count+=temp-a[i+1];
            }
        }
    }
    cout<<count;
}