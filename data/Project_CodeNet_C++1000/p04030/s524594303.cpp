/*****************************************************************************************
******************************AUTHOR:***************************************************
****************************ASHISH RANJAN***********************************************
*****************************************************************************************/
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
  vector<char> v;
string s;
cin>>s;
int n = s.size();
fr(i,n){
if(s[i]=='0'||s[i]=='1')v.push_back(s[i]);
  if(s[i]=='B'&&!v.empty())v.pop_back();
}
for(auto i:v)cout<<i;
 return 0;
  
}
