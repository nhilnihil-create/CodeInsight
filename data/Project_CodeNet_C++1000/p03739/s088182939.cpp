#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
#include <map>
#include <math.h>

using ll = long long;
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll odd_count=0, odd_sum_count=0;
    reps(i, 0, n){
        odd_sum_count+=a[i];
        if(i%2==0){
        while(odd_sum_count>=0){
            odd_sum_count--;
            odd_count++;
        }
        }
        else{
            while(odd_sum_count<=0){
            odd_sum_count++;
            odd_count++;
            }
        }
    }
    

    ll even_count=0, even_sum_count=0;
    reps(i, 0, n){
        even_sum_count+=a[i];
        if(i%2==0){
        while(even_sum_count<=0){
            even_sum_count++;
            even_count++;
        }
        }
        else{
            while(even_sum_count>=0){
            even_sum_count--;
            even_count++;
            }
        }

    }
    cout << min(even_count, odd_count) << endl; 
}