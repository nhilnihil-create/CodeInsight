#include <bits/stdc++.h>
using namespace std;
int main(){
int counter1,counter2;
int N;
cin>>N;
counter1=0;
counter2=0;
int answer=0;
int counter=0;
int i=0;
string S,T; cin>>S>>T;
while(counter1<N){
if(T.at(i)==S.at(counter1)){
answer++;
counter1++;
i++;}
else {
answer=0;
i=0;
counter2++;
counter1=counter2;
continue;}}
cout<<2*N-answer<<endl;}
