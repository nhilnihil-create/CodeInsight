#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    char a,b;
    cin>>a>>b;

    if(a=='H'){
        if(b=='H') cout<< 'H' <<endl;
        else cout<< 'D' <<endl;
    }
    else{
        if(b=='H') cout<< 'D' <<endl;
        else cout<< 'H' <<endl;
    }
    
    return 0;
}