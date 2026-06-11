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
ll n,k,x,y;
  cin>>n>>k>>x>>y;
  if(n<=k){cout<<n*x;return 0;}
  else {cout<<(n-k)*y+k*x;return 0;}
 return 0;
  
}
