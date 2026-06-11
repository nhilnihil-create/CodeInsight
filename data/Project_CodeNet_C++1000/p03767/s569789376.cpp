#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    long long n;
    cin>>n;

    vector<long long> a(3*n);
    REP(i,3*n){
        cin>>a[i];
    }

    sort(ALL(a));
    reverse(ALL(a));
    long long sum=0;

    REP(i,n){
        sum+=a[2*i+1];       
    }

    cout<<sum<<endl;
}