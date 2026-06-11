#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
typedef long long ll;
#define downque(que)  priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;



int main(){
 string s; cin>>s;
 int n=s.size();
 int count=0;
 //gpgpの順が一版効率がいい
REP(i,n){
  if((i+1)%2==1){//奇数番目はつねにgより
    if(s[i]=='p')count--;
  }else{
    if(s[i]=='g')count++;
  }
   
}
cout<<count<<endl;
}

