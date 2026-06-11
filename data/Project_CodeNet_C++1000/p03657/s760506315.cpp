#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;
int main(){
    int a,b;
    cin>>a>>b;
    int c=a+b;
    if(c%3==0||a%3==0||b%3==0){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }

    return 0;
}
