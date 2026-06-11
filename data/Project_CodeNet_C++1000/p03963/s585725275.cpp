#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int sum=1;
    for(int i=0;i<n;i++)
    {
        if(i==0){
            sum=k;
        }
        else{
            sum*=(k-1);
        }
    }
    cout<<sum;
}