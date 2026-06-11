// 全探索
#include <bits/stdc++.h>
using namespace std;
int main(){
    int k,s,i,j,l;
    cin >> k >> s;
    int count = 0;
    for(i=0;i<k+1;i++){
        for(j=i;j<k+1;j++){
            for(l=j;l<k+1;l++){
                int sum = i + j + l;
                if(sum==s){
                    if(i==j&&j==l){
                        count++;
                    }else if(i==j||j==l||l==i){
                        count = count + 3;
                    }else{
                        count = count + 6;
                    }
                }else if(sum>s){
                    break;
                }
            }
        }
    }
    cout << count << endl;
}