#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
//#define ARRAY(type,n) (type *)malloc(sizeof(type)*n)
template<typename T>
T* ARRAY(int n){
	(T*)malloc(sizeof(T)*n);
}
template<typename T>
T** ARRAY2(int m,int n){
	T** type = (T**)malloc(sizeof(T*)*m);
	for(int i=0;i<m;i++){
		type[i]=(T*)malloc(sizeof(T)*n);
	}
	return type;
}

int par[200000];
void init(int n){
	rep(i,n){
		par[i]=i;
	}
}

int root(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x] = root(par[x]);
	}
}

void unite(int x,int y){
	x=root(x);
	y=root(y);
	if(x==y)return;
	par[x]=y;
}

int par2[200000];
void init2(int n){
	rep(i,n){
		par2[i]=i;
	}
}

int root2(int x){
	if(par2[x]==x){
		return x;
	}else{
		return par2[x] = root2(par2[x]);
	}
}

void unite2(int x,int y){
	x=root2(x);
	y=root2(y);
	if(x==y)return;
	par2[x]=y;
}

struct ans{
	int r1;
	int r2;
	int memo;
	int num;
	
};

bool operator< (const ans& left,const ans& right){
        return left.r1 == right.r1 ? left.r2 < right.r2 : left.r1 < right.r1;
    }

class MY_LESS_DEFINITION{
public:
    bool operator() (const ans& left, const ans& right) const {
        return left.num<right.num;
    }
};

int main(void){
	int n,k,l;
	cin>>n>>k>>l;
	int p,q,r,s;
	init(n);
	init2(n);
	rep(i,k){
		cin>>p>>q;
		unite(p-1,q-1);
	}
	rep(i,l){
		cin>>r>>s;
		unite2(r-1,s-1);
	}
	ans answer[n+1];

	rep(i,n){
		answer[i].r1 = root(i);
		answer[i].r2 = root2(i);
		answer[i].num = i;
	}
	sort(answer,answer+n);
	answer[n].r1 = 200001;
	answer[n].r2 = 200001;
	int memo=1;
	int memo2;
	q=0;
	int memoi = 0;
	while(q<=n){
		while(q<=n){
			if(answer[q].r1==answer[q+1].r1&&answer[q].r2==answer[q+1].r2){
				memo++;
				q++;
				continue;
			}else{
				for(int j=memoi; j<memoi+memo;j++){
					answer[j].memo = memo;
				
				}
				break;
			}
		}
		q++;
		memoi = q;
		memo = 1;
	}
	sort(answer,answer+n,MY_LESS_DEFINITION());
	rep(i,n){
		cout<<answer[i].memo<<" ";
	}
	cout<<endl;
	return 0;
}