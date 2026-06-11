#include <bits/stdc++.h>
using namespace std;

long long arr[100005];

int main(){
long long n;
scanf("%lld",&n);
long long sum=0;
for (int x = 0; x<n; x++){
    scanf("%lld",&arr[x]);
    sum += arr[x];
}
if (sum%((n*(n+1LL))/2LL)!=0LL){
    printf("NO");
    return 0;
}
long long t = sum/((n*(n+1))/2);
for (int x = 0; x<n; x++){
    long long diff;
    if (x==0) diff = arr[0]-arr[n-1];
    else diff = arr[x]-arr[x-1];
    if (diff>t){
        printf("NO");
        return 0;
    }
    diff-=t;
    diff = -diff;
    if (diff%n!=0){
        printf("NO");
        return 0;
    }
}
printf("YES");
}
