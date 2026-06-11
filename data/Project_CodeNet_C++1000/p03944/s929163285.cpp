#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int W,H,N;
  	cin>>W>>H>>N;
  	bool black[W][H];
  	int barea=0;
  	rep(i,W){
     	rep(j,H){
         	black[i][j]=false; 
        }
    }
  
  	rep(i,N){
      	int x,y,a;
      	cin>>x>>y>>a;
      	
     	if(a==1){
        	rep(j,W){
             	rep(k,H){
                   if(j<x) black[j][k] = true;
                }
            }
        }
      
      	if(a==2){
        	rep(j,W){
             	rep(k,H){
                   if(j>=x) black[j][k] = true;
                }
            }
        }
      
        if(a==3){
        	rep(j,W){
             	rep(k,H){
                   if(k<y) black[j][k] =true;
                }
            }
        }
      
      	if(a==4){
        	rep(j,W){
             	rep(k,H){
                   if(k>=y) black[j][k] =true;
                }
            }
        }
      
    }	
  	
  	rep(i,W){
     	rep(j,H){
         	 barea+=black[i][j];
        }
    }
  	
  	cout<<W*H-barea<<endl;
  
}