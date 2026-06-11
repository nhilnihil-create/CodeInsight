#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long a[n];
    f(i,0,n){
        cin>>a[i];
    }
    sort(a,a+n);
    vector<long long> b(100002,0);
    f(i,0,n){
        b[a[i]]++;
        b[a[i]+1]++;
        if(a[i]>0){
            b[a[i]-1]++;
        }
    }
    sort(b.begin(),b.end());
    cout<<b[100001]<<endl;
    return 0;
}
