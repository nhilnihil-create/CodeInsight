#include <bits/stdc++.h>
using namespace std;
int main(){
int counter1,counter2;
counter1=0;
counter2=0;
int answer=0;
string S; cin>>S;
for(long long i=0; i<S.size();i++){
if(S.at(i)=='S'){
counter1++;}
else{
if(counter1>0){
counter1--;}
else{
answer++;}}}
cout<<answer+counter1<<endl;}