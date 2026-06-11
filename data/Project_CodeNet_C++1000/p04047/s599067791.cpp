#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll N; cin>>N;
    ll array[2*N];
    for(int i=0; i<2*N; ++i) cin>>array[i];
    sort(array, array+2*N);
    ll sum = 0;
    for(int i=0; i<2*N; i+=2) sum = sum + array[i];
    cout<<sum<<endl;
}