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
string s;
  cin>>s;
  if(s.size()<2){cout<<"-1 -1";return 0;}
  if(s.size()==2){
  if(s[0]==s[1]){cout<<"1 2";return 0;}
    else{cout<<"-1 -1";return 0;}
  }
  fr(i,s.size()-2){
  if(s[i]==s[i+1]){cout<<i+1<<" "<<i+2;return 0;}
    if(s[i]==s[i+2]){cout<<i+1<<" "<<i+3;return 0;}
    if(s[i+1]==s[i+2]){cout<<i+2<<" "<<i+3;return 0;}
  }
  cout<<"-1 -1";
 return 0;
  
}
