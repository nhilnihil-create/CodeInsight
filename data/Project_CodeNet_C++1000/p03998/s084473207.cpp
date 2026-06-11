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
#include<stack>
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
#define frs(i,a,b) for(int i = a;i<b;i++)
#define fvs(i,a,b) for(int i=a;i>=b;i--)
#define meme(a,b,c) memset(a,b,sizeof(c)); //works only for 0 and -1
int main(){
  fast();
 stack<char> a;
stack<char> b;
stack<char> c;
string s1,s2,s3;
int x,y,z;
cin>>s1>>s2>>s3;
fvs(i,s1.size()-1,0)a.push(s1[i]);
fvs(i,s2.size()-1,0)b.push(s2[i]);
fvs(i,s3.size()-1,0)c.push(s3[i]);
x:;
if(a.empty()){cout<<"A";return 0;}
else{
int t = a.top();
  a.pop();
  if(t=='b')goto y;
  if(t=='c')goto z;
  else goto x;
}
y:;
if(b.empty()){cout<<"B";return 0;}
else{
int t = b.top();
  b.pop();
  if(t=='a')goto x;
  if(t=='c')goto z;
  else goto y;
}
z:;
if(c.empty()){cout<<"C";return 0;}
else{
int t = c.top();
  c.pop();
  if(t=='b')goto y;
  if(t=='a')goto x;
  else goto z;
}
 return 0;
  
}


