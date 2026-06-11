#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int n;
cin>>n;
vector<int> m(n);
int ans =0;
for(int i=0;i<n;i++){
int l;
cin>>l;
ans+=l;
m[i]=l;
}
sort(m.begin(),m.end());
int j=0;

while(ans%10==0){
if(m[j]%10==0)j++;
else{
    ans-=m[j];
    break;
}

if(j==n){
    ans=0;
    break;
}


}

cout<<ans<<endl;
}
