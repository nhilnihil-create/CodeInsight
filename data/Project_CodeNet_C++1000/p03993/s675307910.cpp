#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
int rab[200000];
int N;
cin>>N;
rab[0]= 0;
for(int i = 1;i<=N;i++)cin>>rab[i];
int cnt=0;
for(int i = 1;i<=N;i++){
if(i == rab[i] || rab[rab[i]]==i)cnt++;
}
cnt/=2;
cout<<cnt<<endl;
}