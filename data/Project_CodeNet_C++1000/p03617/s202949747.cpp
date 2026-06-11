#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int64_t q,h,s,d;
    cin>>q>>h>>s>>d;
    q*=4;
    h*=2;
    int64_t onelmin=min(min(q,h),s);
    int64_t n;
    cin>>n;
    if(n%2==0){
        cout<<min(onelmin*n,n/2*d)<<endl;
    }
    else{
        cout<<min(onelmin*n,onelmin+(n-1)/2*d)<<endl;
    }
}