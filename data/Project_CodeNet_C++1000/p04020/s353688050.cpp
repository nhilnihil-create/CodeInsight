#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; cin >> N;
    vll A(N+1);
    ll sum = 0;
    vll a(N+1);
    for(int i=1; i<N+1; i++){
        cin >> A[i];
        sum += A[i];
        a[i] = (A[i]%2);
    }
    ll min = 0;
    ll k = 0;
    for(int i=1; i<N+1; i++){
        if(A[i]>0){
            if(a[i]==k){
                k=0;
            }else{
                k=1;
            }
        }else{
            if(k==1){
                min++;
                k=0;
            }
        }
    }
    cout << (sum - min)/2;
}