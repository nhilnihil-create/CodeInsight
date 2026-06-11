#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    string o;
    cin>>o;
    long long s,l,j=0;
    f(i,0,o.size()){
        if(o[i]=='A'&&j==0){
            s=i;
            j=1;
        }
        else if(o[i]=='Z'){
            l=i;
        }
    }
    cout<<l-s+1<<endl;
    return 0;
}
