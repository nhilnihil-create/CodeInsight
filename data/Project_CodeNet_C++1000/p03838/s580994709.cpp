#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007

using namespace std;

int main(){
    lli x,y,ans;
    lli i,j;
    cin>>x>>y;
    if(x==y){
        ans=0;
    }
    else{
        ans=abs(abs(x)-abs(y));
        if(abs(x)>=abs(y)){
            if((x>=0)&&(y>=0)){
                if(y==0){
                    ans+=1;
                }
                else{
                    ans+=2;
                }
            }
            else{
                if((x<=0)&&(y<=0)){
                }
                else{
                    ans+=1;
                }
            }
        }
        else{
            if((x>=0)&&(y>=0)){
            }
            else{
                if((x<=0)&&(y<=0)){
                    if(x==0){
                        ans+=1;
                    }
                    else{
                        ans+=2;
                    }
                }
                else{
                    ans+=1;
                }
            }
        }
    }
    cout<<ans<<endl;
}
