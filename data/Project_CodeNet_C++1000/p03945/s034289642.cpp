#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
 string s;
 cin>>s;
 int count =0;
 for(int i=0;i<s.size();i++){
     if(i+1<s.size()&&s[i+1]!=s[i]){count++;}
 }
 cout<<count<<endl;
 return 0;
}
