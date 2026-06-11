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
int k,t;
string s;
cin>>s;
k = s.size();
if(k<=3){cout<<"No"<<endl;}
else if(s.at(0)=='Y'&&s.at(1)=='A'&&s.at(2)=='K'&&s.at(3)=='I'){
cout<<"Yes"<<endl;}
else{
cout<<"No"<<endl;}}
