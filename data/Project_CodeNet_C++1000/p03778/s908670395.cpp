#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
    int w,a,b;
    cin >> w >> a >> b;
    int ans;
    if(a<=b){
        if(a+w>=b)ans=0;
        else ans=b-a-w;
    }
    else if(b<a){
        if(b+w>=a)ans=0;
        else ans=a-b-w;
    }
    cout << ans << endl;
}