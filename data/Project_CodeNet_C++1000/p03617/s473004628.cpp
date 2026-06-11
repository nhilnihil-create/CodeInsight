#include <bits/stdc++.h>
using namespace std;

int main(){
    
    long long int q,h,s,d;
    cin >> q >> h >> s >> d;
    int n;
    cin >> n;

    long long int price;
    price=min(min(4*q,2*h),s);

    if(n%2){
        price=(n-1)*min(2*price,d)/2+price;
    }
    else{
        price=n*min(2*price,d)/2;
    }

    cout << price << endl;
}