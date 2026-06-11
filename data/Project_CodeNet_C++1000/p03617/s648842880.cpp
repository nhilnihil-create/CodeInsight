#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long q, h, s, d, n, price = 0;
    cin >> q >> h >> s >> d >> n;
    n *= 1000;
    vector<pair<long long,char>>a(4);
    a[0] = make_pair(8*q,'q');
    a[1] = make_pair(4*h,'h');
    a[2] = make_pair(2*s,'s');
    a[3] = make_pair(d,'d');
    sort(a.begin(),a.end());
    for(int i=0; i<4; i++){
        if(a[i].second=='q'){
            long long amount = n / 250;
            n %= 250;
            price += amount * (a[i].first/8);
        }
        if(a[i].second=='h'){
            long long amount = n / 500;
            n %= 500;
            price += amount * (a[i].first/4);
        }
        if(a[i].second=='s'){
            long long amount = n / 1000;
            n %= 1000;
            price += amount * (a[i].first/2);
        }
        if(a[i].second=='d'){
            long long amount = n / 2000;
            n %= 2000;
            price += amount * a[i].first;
        }
        if(n==0){
            cout << price << endl;
            return 0;
        }
    }
    return 0;
}