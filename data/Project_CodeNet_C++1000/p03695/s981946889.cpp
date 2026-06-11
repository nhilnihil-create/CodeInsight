#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
// nCk を取得
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
cout << fixed << setprecision(10);
int n;
cin>>n;
int s[10]={};
int a;
int ca=0;
for(int i=0; i<n; i++){
cin>>a;
if(1<=a&&a<400){
s[0]++;}
else if(400<=a&&a<800){
s[1]++;}
else if(800<=a&&a<1200){
s[2]++;}
else if(1200<=a&&a<1600){
s[3]++;}
else if(1600<=a&&a<2000){
s[4]++;}
else if(2000<=a&&a<2400){
s[5]++;}
else if(2400<=a&&a<2800){
s[6]++;}
else if(2800<=a&&a<3200){
s[7]++;} 
else 
s[8]++;}
for(int i=0; i<=7; i++){
if(s[i]>0){
ca++;}}
int mi,ma;
if(ca==0){
mi=1;}
else{
mi=ca;}
ma=s[8]+ca;
cout<<mi<<" "<<ma<<endl;}
