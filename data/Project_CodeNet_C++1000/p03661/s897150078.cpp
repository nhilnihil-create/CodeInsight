#include <algorithm>
#include <iostream>
#include <stack>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

int ans[100005];
int res[100005];
int kun[100005];

int a[200005][2]={0};

int main(){
    int n;
    cin>>n;
    long long a[200005];
    long long res=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        res+=a[i];
        a[i]=res;
    }
    long long mi=0;
    for(int i=0;i<n-1;i++){
        long long ans=res;
        long long x,y;
        x=a[i];
        y=ans-a[i];
        if(i==0){
            mi=abs(x-y);
        }
        else{
            long long zz=abs(x-y);
            if(zz<mi){
                mi=zz;
            }
        }
    }
    cout<<mi;
}
