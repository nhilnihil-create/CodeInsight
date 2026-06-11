
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef struct pair<int,int> P;
typedef struct pair<int,P> P2;

int n;

ll a[301][301]={};
bool d[301][301]={};
//ll a[100002]={};
//ll b[100002]={};
//ll c[100002]={};

const ll INF=100000000001;
int main() {

	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}

	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			for(int k=0;k<n;++k){
				if((i!=k)&&(j!=k)){
					if(a[i][j]==a[i][k]+a[k][j]){
						d[i][j]=true;
						d[j][i]=true;
					}
					if(a[i][j]>(a[i][k]+a[k][j])){
						cout<<"-1"<<endl;
						return 0;
					}
				}
			}
		}
	}
	ll total=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(!d[i][j])total+=a[i][j];
		}
	}
	cout<<total/2<<endl;
	return 0;
}
