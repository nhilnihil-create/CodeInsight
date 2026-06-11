#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int n;
cin>>n;
int m[200000];
for(int i=0;i<n;i++){
cin>>m[i];
}
int type = 1;
int ans=1;
for(int i=1;i<n;i++){

if(m[i-1]<m[i]){
if(type == 2){
    type=1;
ans++;
}
else {
    type=0;
}
}
else if(m[i-1]>m[i]){
if(type==0){
type=1;
ans++;
}
else{
    type=2;
}
}

}
cout<<ans<<endl;

}