#define ll long long
#define INF 99999999
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#include<bits/stdc++.h>
using namespace std;


int main (){
    ll a,b;
    int ans;
    cin >> a >> b;
    if(0<a){
        cout << "Positive" << endl;
    }else if(0<=b)
    {
        cout << "Zero" << endl;
    }
    else if((b-a+1)%2 == 0){
        cout << "Positive" << endl;
    }
    else
    {
        cout << "Negative" << endl;
    }
    return 0;

}
