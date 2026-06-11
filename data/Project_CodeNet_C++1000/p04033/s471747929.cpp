#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main(){
    int a,b;
    cin>>a>>b;
    if(0<a&&0<b){
        cout<<"Positive"<<endl;
    }
    else if(a<=0&&0<=b){
        cout<<"Zero"<<endl;
    }
    else{
        if((b-a)%2==0){
            cout<<"Negative"<<endl;
        }
        else{
            cout<<"Positive"<<endl;
        }
    }
}