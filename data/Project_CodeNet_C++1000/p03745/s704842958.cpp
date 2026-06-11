#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
#include <map>
#include <math.h>

using ll = long long;
using namespace std;

int main(){
    int n; cin >>n;
    ll a[101000];
    rep(i, n) cin >> a[i];

    bool up_flag=false;
    bool down_flag=false;
    int count = 0;
    rep(i, n){
        if (up_flag==true){
            if(a[i]<=a[i+1]) continue;
            else {
                up_flag=false;
                // count++;
            }
        }
        else if(down_flag==true){
            if(a[i]>=a[i+1]) continue;
            else {
                down_flag=false;
                // count++;
            }
        }
        else if(up_flag==false&&down_flag==false){
            if (a[i]==a[i+1]) continue;
            else if (a[i]<=a[i+1]){
                up_flag=true;
                count++;
            }
            else if(a[i]>=a[i+1]){
                down_flag=true;
                count++;
            }
        }
    }

    out(count);
}