// cut  count atcoder

#include <bits/stdc++.h>
using namespace std;

/*
int main() {
  int n;
  string s;
  cin>>n>>s;
  int ans=0;

  for(int i=0;i<n;i++){
    map<char,int> x,y;
    int cnt=0;

    for(int j=0;j<=i;j++)
    x[s[j]]++;

    for(int j=i+1;j<n;j++)
      y[s[j]]++;


    cout<<"trying to display the map elements "<<endl;

    for(map<char,int>::iterator it= x.begin();it!=x.end();it++)
        cout<<it->first<<" ";

    cout<<"second half"<<endl;

    for(map<char,int>::iterator it = y.begin();it!= y.end();it++)
        cout<<it->first<<" ";

   cout<<endl;

    for(map<char,int>::iterator v= x.begin();v!=x.end();v++){
     if(y.count(v->first)) cnt++;
    }

    //cout<<cnt<<endl;
    ans=max(ans,cnt);

  }
  cout<<ans<<endl;
}

*/



int main(){

 long long n,a,b,pas=0; string s;

 cin>>n>>a>>b;
 cin>>s;

 int foreign = 0;

 for(long long  i=0;i<s.length();i++)
 {

  if(s[i] == 'a'){
      if(pas < a+b){
      cout<<"Yes"<<endl;
       pas++; }
      else cout<<"No"<<endl;
 }
  else if(s[i] == 'b'){

    if(pas < a+b && foreign<b){
        cout<<"Yes"<<endl;
       pas++; }
    else cout<<"No"<<endl;

    foreign++;
 }
  else
    cout<<"No"<<endl;
 }


 return 0;
}


















