#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ln = (1+sqrt(8*n+1))/2;
    int sm = (ln * (ln+1))/2;
    for(int i=1;i<=ln;i++){
        if(sm-n != i) cout << i << endl;
    }
}
