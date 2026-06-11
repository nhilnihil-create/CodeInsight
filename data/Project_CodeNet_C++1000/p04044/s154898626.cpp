#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define me memset
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

int n,len;
string s; 
vector<string> v;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
  	cin>>n>>len;
  	 for(int i=1;i<=n;++i){
  	 	cin>>s;
  	 	v.pb(s);
  	 }

  	 sort(v.begin(),v.end());
  	 for(auto w:v){
  	 	cout<<w;
  	 }



    return 0;
}