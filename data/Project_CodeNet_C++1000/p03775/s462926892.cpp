#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll int x,max,k,count=0;
    cin >> x;
    for(int i=1;i<=sqrt(double(x));i++){
        k=x%i;
        if(k==0){
            max=x/i;
        }
    }
    while(max>0){
        max/=10;
        count++;
    }
    cout << count;
}