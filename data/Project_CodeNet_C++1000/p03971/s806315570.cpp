#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, a, b;
    string  s;
    int sum_b=0;
    int sum=0;
    cin >> n >> a >> b;
    cin >> s;
 
    int len = s.length();
    for(int i=0; i<len; i++){
        if(s.at(i) == 'a'){
            if(sum < (a+b)){
                sum++;
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }else if(s.at(i) == 'b'){
            if(sum < (a+b) && sum_b < b){
                sum++;
                sum_b++;
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }else{
            printf("No\n");
        }
    }
}