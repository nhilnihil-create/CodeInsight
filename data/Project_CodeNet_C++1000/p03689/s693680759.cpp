#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
//typedef pair<int, int> P;
//typedef pair<int, pair<int, int> > PP;
//const int MAX=;

int main(){
	int N,M,a,b;
	cin>>N>>M>>a>>b;
	
	if(N%a==0 && M%b==0)cout<<"No"<<endl;
	else if(N%a==0){
      	cout<<"Yes"<<endl;
		int c=M%b;
		int d=b-c;
		int k=((N-N%a)*(M-M%b))/(N*M-(N-N%a)*(M-M%b))+3;
		int va=k*d;
		int vb=-k*c-1;
		
		rep(i,N){
			rep(j,M){
				if(j%b<c)cout<<va<<" ";
				else cout<<vb<<" ";
			}
			cout<<endl;
		}
	}
	else if(M%b==0){
      	cout<<"Yes"<<endl;
		int c=N%a;
		int d=a-c;
		int k=((N-N%a)*(M-M%b))/(N*M-(N-N%a)*(M-M%b))+3;
		int va=k*d;
		int vb=-k*c-1;
		
		rep(i,N){
			rep(j,M){
				if(i%a<c)cout<<va<<" ";
				else cout<<vb<<" ";
			}
			cout<<endl;
		}
	}
	else{
      	cout<<"Yes"<<endl;
		int d=(a-N%a)*(b-M%b);
		int c=a*b-d;
		int k=((N-N%a)*(M-M%b))/(N*M-(N-N%a)*(M-M%b))+3;
		int va=k*d;
		int vb=-k*c-1;
		
		rep(i,N){
			rep(j,M){
				if(i%a>=N%a && j%b>=M%b)cout<<vb<<" ";
				else cout<<va<<" ";
			}
			cout<<endl;
		}
	}
}