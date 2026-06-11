
// author-Shivam gupta

#include <bits/stdc++.h>


using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define IN(A, B, C) assert( B <= A && A <= C)

#define MP make_pair
#define FOR(i,a) for(int i=0;i<a;i++)

#define FOR1(i,j,a) for(int i=j;i<a;i++)

#define EB emplace_back

#define INF (int)1e9

#define EPS 1e-9

#define PI 3.1415926535897932384626433832795

#define MOD 1000000007

#define read(type) readInt<type>()
#define max1 1000008
#define out(x) cout<<x<<'\n'
#define out1(x) cout<<x<<" "
#define END cout<<'\n'
typedef long int li;

typedef unsigned long int uli;

typedef long long int ll;

typedef unsigned long long int  ull;


void fast(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
void solve(string s){
FOR(i,s.length()-1){
     if(s[i]==s[i+1]) {
    cout<<i+1<<" "<<i+2<<endl;
    return;
  }}
  FOR(i,s.length()-2){
       if(s[i]==s[i+2]) {
    cout<<i+1<<" "<<i+3<<endl;
    return;
  }}
  cout<<-1<<" "<<-1<<endl;
}
int main() {
string s;
cin>>s;
solve(s);
}



