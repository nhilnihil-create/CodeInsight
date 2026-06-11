#include<bits/stdc++.h>
using namespace std;
int main(){
int l, n;
  cin>>l>>n;
  string s1, s2="";
  string mood[l];
  for(int i=0; i<l;i++){
    cin>>s1;
    mood[i]=s1;}
    sort(mood, mood+l);
    for(int i=0; i<l; i++){
    	s2+=mood[i];
	}
  cout<<s2;}
