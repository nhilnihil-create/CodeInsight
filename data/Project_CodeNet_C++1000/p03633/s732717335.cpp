#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

long long GCD(long long a, long long b){
    if(a==0) return b;
    return GCD(b%a, a);
}

int main(){
    int N;cin >>N;
    long long ans; cin >>ans;
    for(int i=1;i<N;i++){
        long long n; cin >> n;
        ans=ans/GCD(ans,n)*n;
    }
    cout << ans<< endl;
}
