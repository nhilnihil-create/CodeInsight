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
#include<cstring>
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
#define meme(a,b,c) memset(a,b,sizeof(c)); //works only for 0 and -1
int main(){
  fast();
string s;
cin>>s;
vector<int> check(26,100);
fr(i,s.size())
{
  check[s[i]-'a']--;
}
fr(i,s.size()){
//  cout<<check[s[i]-'a']<<" ";
if(check[s[i]-'a']%2!=0){cout<<"No";return 0;}
}
cout<<"Yes";
 return 0;
  
}
