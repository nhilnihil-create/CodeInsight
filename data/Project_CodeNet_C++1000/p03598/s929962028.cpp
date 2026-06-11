#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N,K,sum;
sum=0;
cin>>N>>K;
for(int i = 0;i<N;i++){
int x;
cin>>x;
if(x>K/2){
 if(x>=K){
sum+=(x-K)*2;}
else {sum +=(K-x)*2;}
}
else{sum+=x*2;}
}
cout<<sum;
}
