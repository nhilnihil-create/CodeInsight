#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;cin>>n;
    int MAX_N = 100003;
    int a[MAX_N];
    rep(i,MAX_N)a[i]=0;
    
    int tmp;
    rep(i,n){
        cin>>tmp;
        ++a[tmp];
        ++a[tmp+1];
        if(tmp!=0)++a[tmp-1];
    }
    sort(a,a + MAX_N,greater<int>());
    cout<<a[0]<<endl;
	return 0;
}