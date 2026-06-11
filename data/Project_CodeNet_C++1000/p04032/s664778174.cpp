#include "bits/stdc++.h"
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define gcd(a,b) __gcd(a,b)
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vc vector<char>
#define pb(n) push_back(n)
#define pp pop_back()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define type(a) typeid(a).name();
#define print(arr) cout << "[" ;for(unsigned int i=0;i<(unsigned int) arr.size();i++){ (i==arr.size()-1)?cout << arr[i]:cout << arr[i] << ",";}cout << "]" << endl
#define Arr(arr,l) cout << "[" ;for(unsigned int i=0;i<(unsigned int) l;i++){ (i==l-1)?cout << arr[i]:cout << arr[i] << ",";}cout << "]" << endl
#define console(arr) cout << "["<<endl; for(ll i=0;i<(ll)arr.size();++i){cout << " [";for(ll j=0;j<(ll)arr[i].size();++j){(j==(int)arr[i].size()-1)?cout << arr[i][j]:cout << arr[i][j] << ",";}cout << "]"<<endl;} cout << "]"<<endl
#define starting() auto start = high_resolution_clock::now()
#define ending() auto stop = high_resolution_clock::now();auto duration = duration_cast<microseconds>(stop - start);cout << endl << endl << "Execution Time : "<<duration.count()/1000 << " ms" << endl
 
template <typename T1,typename T2>
void mapped(map<T1,T2>m){for(auto ite=m.begin();ite!=m.end();++ite){cout << "'" << ite->first << "'"<<" : "<<ite->second <<endl;}}
 
template <typename T1 , typename T2>
void mappedArr(map<T1,vector<T2>>m){for(auto ity=m.begin();ity!=m.end();++ity){cout << "'"<< ity->first <<"'"<<" : "<<"[";
for(int i=0;i<(int)ity->second.size();++i){(i==(int)ity->second.size()-1)?cout << ity->second[i]:cout << ity->second[i] << ",";}cout << "]"<<endl;}}
 
string int_to_string(int x){ stringstream ss; ss << x; string ni = ss.str(); return ni;}
int char_to_int(char c){ int n = (int)c - 48; return n; }
int string_to_int(string x){ int n; stringstream s(x); s >> n; return n; }
 
template <typename T1,typename T2>
void ArrPair(vector<pair<T1,T2>>vp){for(int i=0;i<(int)vp.size();++i){
cout << "(" << vp[i].first << "," << vp[i].second << ")"<<endl ;}}
 
const int MOD = 1e9 + 7;
const ll INF = 1e18L + 5;

int main(){
  string s;
  cin >> s;
  int start = -1;
  int end = -1;
  for (int i = 0; i < (int)s.size() - 1; ++i){
	  if(s[i] == s[i+1]){
		  start = i + 1;
		  end = i + 2;
		  break;
	  }
	  if(i < (int)s.size() - 2){
		  if(s[i] == s[i+2]){
			  start = i + 1;
			  end = i + 3;
			  break;
		  }
	  }
  }
  cout << start << " " << end;
}






