#include <bits/stdc++.h>
using namespace std;
bool compare(string a, string b) 
{ 
    return (a+b < b+a); 
} 
  
string lexSmallest(string a[], int n) 
{ 
    // Sort strings using above compare() 
    sort(a, a+n, compare); 
  
    // Concatenating sorted strings 
    string answer = ""; 
    for (int i = 0; i < n; i++) 
        answer += a[i]; 
  
    return answer; 
} 
int main(){
   int n,l;
   cin>>n>>l;
   string A[n];
   for(int i=0;i<n;i++) cin>>A[i];
   cout<<lexSmallest(A,n);   
   return 0;
}

