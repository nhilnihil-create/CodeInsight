#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
///1<<3シフト演算子 とは　0001の1を三つずらして1000にする, これは8を表しておりつまりbitは0から7まで
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define CST(x) cout<<fixed<<setprecision(x)
#define PI 3.14159265359
#define MOD 1000000007
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    
    ll n,x;
    cin >> n >> x;
    ll right,left,cnt;
    cnt = 0;

    right = 0;
    
    rep(i,n){

        left = right;
        cin >> right;
        ll sum = left + right;
        if(sum > x){
             right -= (sum - x);
             cnt += sum - x;
        }
        
    }
    cout << cnt << endl;

}