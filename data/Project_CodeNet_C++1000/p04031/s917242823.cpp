#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,cost=0;
    double avg=0;
    vector<ll> A;
    cin>>n;
    A = vector<ll>(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
        avg += (double)A[i]/n;
    }
    avg = (ll)round(avg);
    for(int i=0;i<n;i++){
        cost += pow(A[i]-(ll)avg,2);
    }
    cout<<cost;
    return 0;
}