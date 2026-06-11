#include<iostream>
#include<algorithm>
#include<cmath>
#include<chrono>
#include<vector>
#include<string>
using namespace std;
using namespace std::chrono;
/*
auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
*/
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define mod 1000000007
#define fr(i,n) for(int i=0;i<(int)n;i++)
int main(){
  fast();
  vector<int> d(100000,0);
    int x,l,t;
  cin>>x>>l;
  fr(i,l){
  cin>>t;
    d[t] = 1;
  }
  for(int i=x;i<100001;i++){
  string s = to_string(i);
    fr(j,s.size()){
    if(d[s[j]-'0'])goto y;
    }
    cout<<s;
    break;
    y:;
  }
  return 0;
  
}