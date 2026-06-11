#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
   	#endif
    int n,m;
    cin>>n>>m;
    cout<<(n*n)-m;
   return 0;
}