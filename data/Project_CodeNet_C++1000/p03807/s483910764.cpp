#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
int main(){
    int n;cin>>n;
    int tmp,cnt=0;
    fo(i,n){
        cin >>tmp;
        if(tmp%2!=0){
            ++cnt;
        }
    }
    (cnt%2==0)?(cout<<"YES"):cout << "NO";
}
