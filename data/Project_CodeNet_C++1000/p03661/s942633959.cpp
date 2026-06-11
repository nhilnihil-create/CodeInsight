#include <bits/stdc++.h>
using namespace std;
long long a[200010],sum[200010];
typedef long long LL;
LL absll(LL a){
    if(a<0){
        return -a;
    }else{
        return a;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    }
    long long minn = 0x9f9f9f9f;
    long long all = sum[n];
    for(int i=1; i<=n-1; i++){
        long long back = all-sum[i];
        if(absll(back-sum[i])<minn){
            minn = absll(back-sum[i]);
        }
    }
    cout << minn <<endl;
    return 0;
}