#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
        int k,s;    cin>>k>>s;
        int c=0;
        rep(i, k+1){
                rep(j, k+1){
                        int z=s-(i+j);
                        if(z<=k && z>=0)
                        c++;
                }
        }
        cout<<c<<endl;



}