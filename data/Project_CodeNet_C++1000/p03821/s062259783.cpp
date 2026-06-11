#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i) >> b.at(i);
    }
    ll sum=0;
    for(int i=n-1; 0<=i; i--){
        if((sum+a.at(i))%b.at(i)==0) continue;
        sum += b.at(i)-(sum + a.at(i))%b.at(i);
    }
    cout << sum << endl;
}
  