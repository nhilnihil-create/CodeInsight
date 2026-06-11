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
#define MOD 1000000007
int main(){
    ll N;
    cin >> N;
    ll a[N];
    ll i;
    ll sum1=0,sum2=0;
    ll cnt1=0,cnt2=0;
    ll t=1;
    for(i=0;i<N;i++){
        cin >> a[i];
        sum1+=a[i];
        sum2-=a[i];
        if(sum1*t<=0){
            cnt1+=abs(sum1)+1;
            sum1=t;
        }
        if(sum2*t<=0){
            cnt2+=abs(sum2)+1;
            sum2=t;
        }
        t*=-1;
    }
    cout << min(cnt1,cnt2);
    return 0;
}
