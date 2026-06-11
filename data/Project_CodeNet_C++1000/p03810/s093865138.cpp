#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
ll a[100001];
ll gcd(ll x,ll y){
if(y==0)
    return x;
else return gcd(y,x%y);
}
int solve(int n,int o){
int i;
int x=0;
int y=0;
int in;
ll v=0;
ll g=gcd(a[1],a[2]);
for(i=3;i<=n;i++)
    g=gcd(g,a[i]);

for(i=1;i<=n;i++)
    {a[i]=a[i]/g;


    };
for(i=1;i<=n;i++){
    if(a[i]%2){
        y++;
   v=max(v,a[i]);
      in=i;
    }
    else{
        x++;


    }}


    if((x%2)&&(x<n))
        return o;
    if(((x%2)==0)&&y>=2)
        return (o^1);
    if((x%2)==0&&(y==1)&&(v==1))
        return (o^1);
    a[in]=a[in]-1;
    return solve(n,o^1);

}







int main(){

int n;
cin>>n;
int i;
for(i=1;i<=n;i++)
    cin>>a[i];
    if(n==1){
        if(a[1]%2)
            cout<<"Second"<<endl;
        else
            cout<<"First"<<endl;
            return 0;

    }
  int x=solve(n,0);
  if(x==0)
        cout<<"First"<<endl;
  else
    cout<<"Second"<<endl;














return 0;}
