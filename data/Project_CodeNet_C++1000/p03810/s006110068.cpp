#include <bits/stdc++.h>
using namespace std;

long long arr[100000];

long long gcd(long long a,long long b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}

int main(void) {
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=0;i<n;i++) {
        scanf("%lld",&arr[i]);
        sum+=arr[i];
    }
    if (sum%2!=n%2) {
        printf("First");
        return 0;
    }
    int cnt=0;
    for(int i=0;i<n;i++) {
        cnt+=arr[i]%2;
    }
    if (cnt>1) {
        printf("Second");
        return 0;
    }
    bool turn=false;
    while (1) {
        bool flag=false;
        for(int i=0;i<n;i++) {
            if (arr[i]!=1) {
                flag=true;
            }
        }
        if (!flag) {
            printf("%s",turn?"First":"Second");
            return 0;
        }
        int cnt=0;
        long long sum=0;
        for(int i=0;i<n;i++) {
            if (arr[i]%2==1) {
                cnt++;
            }
            sum+=arr[i];
        }
        if (sum%2!=n%2) {
            printf("%s",turn?"Second":"First");
            return 0;
        }
        if (cnt>1) {
            printf("%s",turn?"First":"Second");
            return 0;
        }
        for(int i=0;i<n;i++) {
            if (arr[i]%2==1) {
                if (arr[i]==1) {
                    printf("%s",turn?"First":"Second");
                    return 0;
                }
                arr[i]--;
                break;
            }
        }
        long long val=0;
        for(int i=0;i<n;i++) {
            val=gcd(val,arr[i]);
        }
        for(int i=0;i<n;i++) {
            arr[i]/=val;
        }
        turn^=1;
    }
}