#include <iostream>
#include <cmath>
using namespace std;
long long keta(long long a, long long b){
    if(a>b){
        long long cnt=0;
        while(a!=0){
            a /= 10;
            cnt++;
        }
        return cnt;
        return 0;
    }else{
        long long cnt=0;
        while(b!=0){
            b /= 10;
            cnt++;
        }
        return cnt;
        return 0;
    }
}
int main(){
    long long n, a, b, ans=1e15;
    cin >> n;
    for(long long i=1LL; i*i<=n; i++){
        if(n%i!=0) continue;
        else{
            a = i;
            b = n/i;
        }
    }
    cout << keta(a,b) << endl;
    return 0;
}