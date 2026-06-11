#include<bits/stdc++.h>
using namespace std;
long ncr(int n,int r){
    long ans = 1;
    int rr = 2;
    for(int i=n-r+1;i<=n;i++){
        ans *= i;
        while(rr <= r && ans % rr == 0){
            ans /= rr;
            rr++;
        }
    }
    return ans;
}



int main(){
    int n,p;
    cin >> n >> p;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int odd = 0;
    int even = 0;
    for(int i=0;i<n;i++){
        if(a[i] %2 == 0)even++;
        else odd++;
    }
    long oddSum = 0;
    long evenSum = 0;
    if(p==0){
        for(int i=0;i<=even;i++){
            evenSum += ncr(even,i);
        }
        for(int i=0;i<=odd;i+=2){
            oddSum += ncr(odd,i);
        }
    }else{
        for(int i=0;i<=even;i++){
            evenSum += ncr(even,i);
        }
        for(int i=1;i<=odd;i+=2){
            oddSum += ncr(odd,i);
        }
    }
    cout << oddSum * evenSum << endl;
}
