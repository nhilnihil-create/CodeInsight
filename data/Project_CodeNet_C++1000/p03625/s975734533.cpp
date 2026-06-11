#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll ma1=-1,ma2=-1;
    cin >> n;
    vector<ll> a(n);

    for(int i=0 ; i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    for (int i=0;i<n-1;i++){
        if (a[i]==a[i+1]){
            if (ma1==-1){
                ma1=a[i];
                i++;
            }
        
            else {
                cout << a[i]*ma1<<endl;
                return 0;
            }
        }
        
    }

    cout<<0<<endl;

    return 0;
}