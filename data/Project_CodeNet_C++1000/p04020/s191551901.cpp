#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N,A;
    cin >> N;
    ll i;
    ll ans=0;
    ll t=0;
    for(i=0;i<N;i++){
        cin >> A;
        ans+=(A+t)/2;
        if(A!=0)t=(A+t)%2;else t=0;
    }
    cout << ans;
    return 0;
}
