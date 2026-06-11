#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long h[N];
long long n;
long long a,b;
bool check(long long x){
    long long dis = x*b; //攻击x次，所以每个至少受到x*b
    long long dd = a-b;
    long long sum=0;
    for(long long i = n ; i >= 1 ; i -- ){
        if(h[i]>dis){
            if((h[i]-dis)%dd){
                sum += (h[i]-dis)/dd + 1;
            }
            else sum += (h[i]-dis)/dd;
        }
    }
    if(sum<=x) return true;
    else return false;
}

int main()
{

    long long sum=0;
    cin>>n>>a>>b; //假设所有受到b，对象额外 a-b
    for(long long i = 1 ; i <= n ; i++ ){
        cin>>h[i];
        sum+= (h[i]/b)+1;
    }
    sort(h+1,h+1+n);
    long long l = 1, r = sum;
    long long mid;
    while(l<r){
         mid = (l + r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
