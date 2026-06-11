#include<bits/stdc++.h>
#define fr(i,j,n)   for(int i=j;i<n;i++)
#define pb          push_back
#define rf(i,j,p)   for(int i=p;i>=j;i--)
#define vi          vector<int>
#define vll         vector<long long>
#define ll          long long
#define hmm         "\n"
#define sp          " "
#define srt(v)      sort(v.begin(), v.end());
#define down        cout<<hmm;
#define faaast      ios_base::sync_with_stdio(0);cin.tie(nullptr);
using namespace std;
int main()
{
 int n ; cin >> n ;
 int a[3*n];
 fr(i,0,3*n)cin>>a[i];
 sort(a,a+3*n);
 int i = 2 ; ll sum = 0, cnt=0 ;
 while(cnt<n)
 {
     sum+=a[3*n-i];
     i+=2;
     cnt++;
     
 }
cout<<sum<<hmm;
 //return main();
}
