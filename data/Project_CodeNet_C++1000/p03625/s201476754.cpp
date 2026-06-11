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
#include<bitset>
#include<math.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin >> N;
    ll A[N];
    ll i;
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A,A+N);
    ll a=0,b=0;
    for(i=N-1;i>0;i--){
        if(A[i]==A[i-1]){
            if(a==0)a=A[i];else if(b==0)b=A[i];
            i--;
        }
    }
    cout << a*b;
    return 0;
}
