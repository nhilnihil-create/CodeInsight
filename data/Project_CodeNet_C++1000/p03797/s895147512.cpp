#include<bits/stdc++.h>
#define dbug printf("I am here\n");
#define Fast ios_base::sync_with_stdio(false); cin.tie(0);
#define vs            v.size()
#define ss            s.size()
#define sot(v)        sort(v.begin(),v.end())
#define rev(v)        reverse(v.begin(),v.end())
#define ii            pair<int, int>
#define int           long long
#define ull           unsigned long long
#define pb            push_back
#define mpp           make_pair
#define Okay          0
#define pi            3.14159

const int inf = 1e6;
const int cont = 1e18;
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    int fans;
    if(n<m){
    int ans = n*2;
    if(ans <= m){
        m -= ans;
        ans = m/4;
        fans = n+ans;
    }
    else {
        fans = m/2;
    }
    cout<<fans<<endl;
    }else{
        cout<<m/2<<endl;
    }
}

int32_t main(){
   Fast;

   solve();
    return Okay;
}

