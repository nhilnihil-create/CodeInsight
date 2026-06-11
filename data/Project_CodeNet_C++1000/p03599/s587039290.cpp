#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    ll i=0,j=0,k=0,l=0;
    double mx=0,tmp;
    ll ans1=100*A,ans2=0;
    while(100*A*i<=F){
        j=0;
        while(100*(A*i+B*j)<=F){
            k=0;
            while(100*(A*i+B*j)+C*k<=F){
                l=0;
                while(100*(A*i+B*j)+C*k+D*l<=F){
                    if(i+j!=0){
                        tmp=(double)(100*(C*k+D*l))/(double)(100*(A*i+B*j)+C*k+D*l);
                        if((A*i+B*j)*E>=C*k+D*l&&tmp>=mx){
                            mx=tmp;
                            ans1=100*(A*i+B*j)+C*k+D*l;
                            ans2=C*k+D*l;
                        }
                    }
                    l++;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    cout << ans1 <<" "<<ans2 << endl;
    return 0;
}
