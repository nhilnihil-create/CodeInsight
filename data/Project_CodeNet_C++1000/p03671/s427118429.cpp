#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int a[3];
    REP(i,3){
        cin>>a[i];
    }
    sort(a,a+3);
    cout<<a[0]+a[1]<<endl;
    }
