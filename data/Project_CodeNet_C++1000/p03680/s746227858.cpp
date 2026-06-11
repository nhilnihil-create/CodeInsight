#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N;
cin>>N;
vector <int> vec(N);
for(int i =0;i<N;i++){
cin>>vec.at(i); //1の行先はvec[0]
}
int cnt=0;
int j=1; //今いる場所
while(j!=2&&cnt<N){
j=vec.at(j-1);
cnt+=1;}
if(cnt>=N){
cout<<-1;}
else{
cout<<cnt;}
}
