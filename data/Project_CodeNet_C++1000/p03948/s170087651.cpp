#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int main(){
    int n,t;
    cin >> n >> t;
    long a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    long temmin = 1e9+7;
    int cnt = 0;
    long temmax = 0;
    for(int i = 0;i<n;i++){
        temmin = min(a[i],temmin);
        if(a[i]!=temmin){
            if(temmax<a[i]-temmin){
                temmax=a[i]-temmin;
                cnt=1;
            }
            else if(temmax==a[i]-temmin){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}