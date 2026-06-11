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
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    ll i;
    cin >> N;
    ll A[N];
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    ll ans=0;
    for(i=0;i<N;i++){
       if(A[A[i]-1]==i+1)ans++;
    }
    cout << ans/2;
    return 0;
}