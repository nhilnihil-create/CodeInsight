#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
int main() {
ll n;
cin>>n;
ll f=0;
ll counter=0;
ll ca=0;
string a;
cin>>a;
for(ll i=0; i<n; i++){
if(a.at(i)==')'){
counter++;}
else{
ca++;}
if(counter>ca){
cout<<"(";
ca=0;
counter=0;}
}
f=ca-counter;
for(ll i=0; i<n; i++){
cout<<a.at(i);}
for(ll i=0; i<f; i++){
cout<<")";}
cout<<endl;}
