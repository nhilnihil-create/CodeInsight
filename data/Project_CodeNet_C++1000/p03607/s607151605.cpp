#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)

#define ll long long

#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));

int main(){
	ll N;
  cin >> N;
  map<ll,ll> a;
  froop1(0,N){
   ll b;
    cin >> b;
    if(a.count(b)){
      a.erase(b);
    }else{
      a[b] = 1;
    }
  }
  ll count = 0;
  for(pair<ll,ll> p : a){
   count++;
  }
  cout << count << endl;
}