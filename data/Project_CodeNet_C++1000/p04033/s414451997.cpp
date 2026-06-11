#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    ll a, b;
    cin >> a >> b;

    if(a > 0){
        cout << "Positive" << endl;
        return 0;
    }else if(a == 0){
        cout << "Zero" << endl;
        return 0;
    }else if(a < 0 && b >= 0){
        cout << "Zero" << endl;
        return 0;
    }

    if(abs(a - b) % 2 == 0){
        cout << "Negative" << endl;
    }else{
        cout << "Positive" << endl;
    }



    return 0;
}