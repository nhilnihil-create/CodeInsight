#include<iostream>
#include<algorithm>
#include<cmath>
#include<chrono>
#include<vector>
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
#define for(i,n) for(int i=0;i<(int)n;i++)
int main(){
  fast();
int t,l;
  cin>>t>>l;
  vector<string> v(t);
  for(i,t)cin>>v[i];
  sort(v.begin(),v.end());
  for(i,t)cout<<v[i];
  return 0;
  
}