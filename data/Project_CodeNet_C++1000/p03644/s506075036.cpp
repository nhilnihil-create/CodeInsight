#include <bits/stdc++.h>
#include <math.h>
using namespace std;


int main(){
    int n;cin >>n;
    int max_count = 0;
    int ans = 1;
    for(int i=0;i<n;i++){
        int count =0;
        int num = i+1;
        while(num%2==0){
            count++;
            num = num/2;
        }
        if(max_count < count){
            max_count = count;
            ans = i+1;
        }
    }

    printf("%d",ans);

}