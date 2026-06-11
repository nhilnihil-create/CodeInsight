#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,time,su;
    std::cin >> x;
    for (int i = 1; i < 100000000; i++) {
        /* code */
        su+=i;
        time++;
        if(su>=x){
            if(su==x)break;
            if(su%2==1){
               // time=time+1;
                break;
            }
            else{
                //time=time+1;
                break;
            }
        }
    }
    std::cout << time << std::endl;
}
