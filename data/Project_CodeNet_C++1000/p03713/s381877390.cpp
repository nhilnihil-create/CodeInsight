#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long int make(long long int a,long long int b){
    long long int result=b/3;
    long long int rem=b%3;
    long long int r1=result,r2=result,r3=result;
    if(rem>=1){
        r2++;
    }
    if(rem>=2){
        r3++;
    }
    long long int a1=r1*a;
    long long int a2=r2*a;
    long long int a3=r3*a;
    long long int max1=max(a1,max(a2,a3));
    long long int min1=min(a1,min(a2,a3));
    return max1-min1;
}
long long int second(long long int a,long long int b){

    long long int height=ceil(b/3.0);
    long long int rem=b-height;
    long long int first=a/2;
    long long int second=a-first;
    long long int a1=first*rem;
    long long int a2=second*rem;
    long long int a3=height*a;
    long long int max1=max(a1,max(a2,a3));
    long long int min1=min(a1,min(a2,a3));
    long long int result1=max1-min1;
    height=(b/3.0);
    rem=b-height;
    first=a/2;
    second=a-first;
    a1=first*rem;
     a2=second*rem;
    a3=height*a;
    long long int max2=max(a1,max(a2,a3));
    long long int min2=min(a1,min(a2,a3));
    long long int result2=max2-min2;
    return min(result1,result2);
}

int main(){
    long long int a,b;
    cin>>a>>b;
    vector<long long int>v;
    long long int area1=make(a,b);
    long long int area2=make(b,a);
    long long int area3=second(a,b);
    long long int area4=second(b,a);
    long long int finalresult=min(area1,min(area2,min(area3,area4)));
    cout<<finalresult;
}