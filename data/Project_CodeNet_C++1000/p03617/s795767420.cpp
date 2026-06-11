#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    ll q,h,s,d,n;
    cin >> q >> h >> s >> d >> n;
    h = min(h,2*q);
    s = min(s,2*h);
    if(2*s<=d){
        cout << s*n << endl;
        
    }else {
        if(n%2==0){
            cout << d*n/2 << endl;
            
        }else{
            cout << d*(n/2)+s << endl;
            
        }
    }
    return 0;
}