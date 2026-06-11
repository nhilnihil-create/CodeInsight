#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
int h,w,x,y;
int main(){
  cin>>h>>w>>x>>y;
  if(h%x==0&&w%y==0)cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    if(w%y==0){
      lol(i,h){
	lol(j,w){
	  if(j)cout<<" ";
	  if(i%x==0)cout<<"600";
	  else if(i%x==x-1)cout<<"-601";
	  else cout<<"0";
	}
	cout<<endl;
      }
    }
    else{
      lol(i,h){
	lol(j,w){
	  if(j)cout<<" ";
	  if(j%y==0)cout<<"600";
	  else if(j%y==y-1)cout<<"-601";
	  else cout<<"0";
	}
	cout<<endl;
      }
    }
  }
 return 0; 
}
