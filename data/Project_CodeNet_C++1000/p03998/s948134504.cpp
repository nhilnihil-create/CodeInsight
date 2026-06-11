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
string sa,sb,sc;
cin>>sa>>sb>>sc;
ll a=1;
for(ll i=1; i>0; i++){
if(a==1){
if(sa.size()==0){
cout<<'A'<<endl;
break;}
if(sa.at(0)=='a'){
a=1;}
else if(sa.at(0)=='b'){
a=2;}
else
a=3;
sa=sa.substr(1,sa.size()-1);}
if(a==2){
if(sb.size()==0){
cout<<'B'<<endl;
break;}
if(sb.at(0)=='a'){
a=1;}
else if(sb.at(0)=='b'){
a=2;}
else
a=3;
sb=sb.substr(1,sb.size()-1);}
if(a==3){
if(sc.size()==0){
cout<<'C'<<endl;
break;}
if(sc.at(0)=='a'){
a=1;}
else if(sc.at(0)=='b'){
a=2;}
else
a=3;
sc=sc.substr(1,sc.size()-1);}}}

