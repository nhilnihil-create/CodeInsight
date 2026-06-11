#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int calc(ll A, ll B){
    int retA=0;
    while(A>0){
        retA++;
        A/=10LL;
    }
    int retB=0;
    while(B>0){
        retB++;
        B/=10LL;
    }
    return max(retA,retB);
}

int main(){
    ll N;
    cin >> N;
    int ans=MOD;
    for(ll i=1; i*i<=N; i++){
        if(N%i==0){
            ans=min(ans,calc(i,N/i));
        }
    }
    cout << ans << endl;
}