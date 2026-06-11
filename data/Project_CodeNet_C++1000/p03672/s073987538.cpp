#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    long long int N,H,W,i,j,k,ans,count,cost,tmp;
    long long int S[200010];
    long long int Ssum[200010];
    string T,U,V,ans2;
    bool flag;
    count=0;
    ans=std::pow(10,18);
    flag=false;
    cin >>T;
    for (i=T.size()-1;i>0;i--){
        //cout <<i <<endl;
        if (i%2==0){
            U=T.substr(0,i/2);
            V=T.substr(i/2,U.size());
            if (U==V){
                ans=U.size()*2;
                cout << ans<<endl;
                return 0;
            }
            
            
            }
        }
    
    

    
    //cout << ans<<endl;

    return 0;
    
}
