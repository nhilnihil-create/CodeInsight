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

    vector<ll> vec(N+1,0);
    ll tmp=0;
    for(int i=0; i<N; i++){
        ll x;
        cin >> x;
        x++;
        tmp=max(tmp,i+1-(x-(x/2+x%2)));
        vec[i+1]=max(0LL,tmp);
    }
    vec[N]=MOD;

    ll ans=1;
    int h=0;
    ll cnt=0;
    for(int i=0; i<N; i++){
        while(vec[h]<=i){
            h++;
            cnt++;
        }

        ans*=cnt;
        ans%=MOD;
        cnt--;
        //cout << ans << endl;
    }
    cout << ans << endl;
}