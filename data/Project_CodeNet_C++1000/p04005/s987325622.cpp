#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
ll A, B,C;
cin>>A>>B>>C;
ll ans;
if(A%2==0 ||B%2==0||C%2==0)ans = 0;
else{
vector<ll> a(3);
a[0]=A;
a[1]=B;
a[2]=C; 
sort(a.begin(),a.end());
ans = a[0]*a[1];
}
cout<<ans<<endl;
}
