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
int n;
cin>>n;
int arr[n];
fr(i,n)cin>>arr[i];
int avg = 0,sum = 0;
fr(i,n)sum += arr[i];
  avg = sum/n;
int ans = 0;
  int p=0,q=0;
fr(i,n){p += ((arr[i]-avg)*(arr[i]-avg));
        q += ((arr[i]-(avg+1))*(arr[i]-(avg+1)));    
}
  ans = min(p,q);
cout<<ans;
 return 0;
  
}
