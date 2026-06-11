#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define ALL(x) x.begin(),x.end()
#define VI vector<int> 
using namespace std;
/*..................DEFINE GLOBAL VARIABLES...................*/
VI v(100005);
/*.....................DEFINE FUNCTIONS ......................*/
/*.........................kemkemG0...........................*/
int main() {int N;cin >> N;VI a(N);REP(i, N){int a; cin>>a;v[a]++;v[a+1]++;if(a!=0)v[a-1]++;}sort(ALL(v),greater<int>());cout<<v[0]<<endl;return 0;}
