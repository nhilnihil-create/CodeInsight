#include <iostream>
#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> pq;
int main(){
    long long n;
    cin>>n;
    cout<<50<<endl;
    for(long long i=1;i<=50;i++){
        cout<<n/50 + (50-i) + (n%50>(i-1))<<" ";
    }
}