#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    ll a,b;
    cin >> a >> b;
    if(a<=0 && b >= 0){
        cout << "Zero" << endl;
        return 0;
    }
    if(a>0){
        cout << "Positive"<< endl;
        return 0;
    }
    if(b>0 && abs(a)%2 == 0){
        cout << "Positive"<< endl;
        return 0;
    }
    if((b-a+1)%2 == 0){
        cout << "Positive"<< endl;
        return 0;
    }
    cout << "Negative" << endl;
    return 0;
}