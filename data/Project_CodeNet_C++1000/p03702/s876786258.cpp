#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define re return
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii; 
int n,a,b;
int h[100010];
int ans;
bool check(long long mid){
	long long sum=0;
    for(int i=0;i<n;i++){
		if(h[i]-mid*b>0)
   		sum+=(h[i]-mid*b+a-b-1)/(a-b);
  	}
 	return sum<=mid;
}
int main(){	
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
 		cin>>h[i];
	}
	int mid,l,r;
	l=0;
	r=1e9;
	while(l<=r){
 		mid=(l+r)/2;
 		if(check(mid)==1){
  			ans=mid;
  			r=mid-1;
 		}		
 		else
  		l=mid+1;
	}
	cout<<ans;
    return 0; 
}