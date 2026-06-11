#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int n;
cin>>n;
int c[200];
for(int i=0;i<n;i++)cin>>c[i];
bool d[11];
for(int i=0;i<9;i++)d[i]=0;
int red = 0;

for(int i=0;i<n;i++){
if(c[i]>=3200)red++;
else if(c[i]>=2800)d[0]=1;
else if(c[i]>=2400)d[1]=1;
else if(c[i]>=2000)d[2]=1;
else if(c[i]>=1600)d[3]=1;
else if(c[i]>=1200)d[4]=1;
else if(c[i]>=800)d[5]=1;
else if(c[i]>=400)d[6]=1;
else d[7]=1;
}
int ans=0;

for(int i=0;i<9;i++){
    if(d[i]==1) ans++;
}
cout<<max(ans,1)<<" "<<ans+red<<endl;


}
