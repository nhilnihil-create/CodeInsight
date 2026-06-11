#include<bits/stdc++.h>
using namespace std;

int main(){
    int q,h,s,d;
    long long n;
    cin >> q >> h >> s >> d >> n;
    n=n*4;
    map<int,int> price;
    price[q*8]=1;
    price[h*4]=2;
    price[s*2]=4;
    price[d]=8;
    long long ans = 0;
    for(auto p:price){
        int cost = p.first;
        int volume = p.second;
        ans += cost*volume/8*(n/volume);
        n -= (n/volume)*volume;
        if(n==0) break;
    }
    cout << ans << endl;
}