#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
const int MOD = 1000000007;
using namespace std;

int main(){
    int N,maxnum=1,maxcount=0;

	cin >> N;
    for(int i=1;i<=N;i++){
        int num = i;
        int count = 0;
        while(true){
            // printf("%d ",num);
            if(num%2!=0 || num == 0){
                break;
            }else{
                num /= 2;
                count++;
            }
        }
        // printf("\n");
        if(count>maxcount){
            maxcount=count;
            maxnum = i;
        }
    }
    cout << maxnum << endl;
}