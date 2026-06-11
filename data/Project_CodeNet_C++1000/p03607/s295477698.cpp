#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int n;
cin>>n;
set<int> m;
for(int i=0;i<n;i++){
int l;
cin>>l;
if(m.count(l))m.erase(l);
else m.insert(l);
}
cout<<m.size()<<endl;
}