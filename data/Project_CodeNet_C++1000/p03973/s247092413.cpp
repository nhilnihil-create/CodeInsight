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

int main(){
    int N;
    cin >> N;
    ll ans=0;
    ll min_=1;
    for(int i=0; i<N; i++){
        ll a;
        cin >> a;

        ll tmp=(a-1)/min_;
        if(tmp==0){
            min_=max(a+1, min_);
        }else{
            ans+=tmp;
            if(i==0){
                min_=2;
            }
        }
    }
    cout << ans << endl;
}