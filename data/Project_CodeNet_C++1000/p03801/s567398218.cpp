#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int binary(vector<int> &k,int left,int right,int key){
  if(k[0]>=key)return 0;
  int mid=(left+right)/2;
  if(left==mid){
    if(k[left]<key)return right;
    else return mid;
  }
  if(k[mid-1]<key)return binary(k,mid,right,key);
  else return binary(k,left,mid,key);
}
int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n)cin >> a[i];
  vector<int> k(1,a[0]);
  vector<int> u(1,0);
  rep(i,n){
    if(i==0)continue;
    if(a[i]>k[k.size()-1]){
      u.push_back(i);
      k.push_back(a[i]);
    }
  }
  vector<int> b(k.size(),0);
  vector<ll> ans(k.size(),0);
  rep(i,n){
    int e=binary(k,0,k.size(),a[i]);
    if(e!=0){
      b[e-1]++;
      ans[e]+=(ll)a[i]-k[e-1];
    }
    else ans[0]+=a[i];
  }
  rep(i,k.size()-1){
    b[k.size()-2-i]+=b[k.size()-1-i];
  }
  rep(i,k.size()-1){
    if(i!=0)ans[i]+=(ll)b[i]*(ll)(k[i]-k[i-1]);
    else ans[i]+=(ll)b[i]*(ll)k[0];
  }
  vector<ll> o(n,0);
  rep(i,k.size())o[u[i]]+=ans[i];
  rep(i,n)cout << o[i] << endl;
}
