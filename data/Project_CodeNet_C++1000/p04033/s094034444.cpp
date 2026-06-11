#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int a,b; cin >> a >> b;
    string ans;
    if(a == 0 || b == 0) ans = "Zero";
    if(a<0&& b>0) ans = "Zero";
    if(a>0&& b<0) ans = "Zero";
    if(a>0&& b>0) ans = "Positive";
    if(a<0&& b<0){
        if((b-a)%2 == 0) ans = "Negative";
        else ans = "Positive";
    }
    cout << ans << endl;
}
