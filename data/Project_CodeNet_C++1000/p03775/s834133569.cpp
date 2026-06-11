#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

long long int getmaxdigit(long long int a,long long int b){
    long long int count1=0,count2=0;
    while(a!=0){
        a/=10;
        count1++;
    }
    while(b!=0){
        b/=10;
        count2++;
    }
    return max(count2,count1);
}


int main(){
    long long int n;
    cin>>n;
    long long int min=INT_MAX;
    for(long long int i=sqrt(n);i>=1;i--){
        if(n%i==0){
            long long int result=getmaxdigit(i,n/i);
            if(min>result){
                min=result;
            }
        }
    }
    cout<<min<<endl;
}