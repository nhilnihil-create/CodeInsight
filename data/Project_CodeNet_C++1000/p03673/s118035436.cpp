#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int n;
cin>>n;
vector<int> a(200010);
for(int i=0;i<n;i++){
cin>>a[i];
}
deque<int> b;
for(int i=0;i<n;i++){
if(i%2==0)b.push_back(a[i]);
else b.push_front(a[i]);
}
if(n%2==1)reverse(b.begin(),b.end());
for(int i=0;i<n;i++){
cout<<b[i]<<" ";
}
cout<<endl;
}