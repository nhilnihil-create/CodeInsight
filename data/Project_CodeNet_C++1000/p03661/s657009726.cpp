 #include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
 int wari(int a,int b) {
   if(a%b==0)
     return a/b;
   else
     return a/b+1;
 }
 int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
 }
 int souwa(int a){
  return a*(a+1)/2;
 }
 int lcm(int a,int b){
  int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return d*e/f;
    }
  int gcm(int a,int b){
      int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return f;
  }
signed main(){
  int a,e=1000000000000000;
  cin>>a;
  vector<int> b(a),c(a,0),d(a,0);
  fo(i,a)
    cin>>b[i];
  c[0]=b[0];
  d[0]=b[a-1];
  for(int i=1;i<a;i++)
    c[i]=c[i-1]+b[i];
  for(int i=1;i<a;i++)
    d[i]=d[i-1]+b[a-1-i];
  c.pop_back();
  d.pop_back();
  rev(d);
  fo(i,a-1)
    e=min(e,abs(c[i]-d[i]));
  cout<<e<<endl;
}
