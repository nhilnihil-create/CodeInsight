#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
        int n, m;
        cin>>n>>m;
        int ans[51]={};
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            ans[a]++;
            ans[b]++;
        }
        for(int i =1; i<=n; i++){
            cout<<ans[i]<<endl;
        }
}
