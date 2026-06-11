#include<iostream>
#include<string>

using namespace std;

int32_t get_num_32(void){
    int32_t x;
    scanf("%d",&x);
    return x;
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    N = get_num_32();
    int i;
    int n=0;
    for(i=0;i<=N;i++){
        n += i;
        if(n >= N){
            break;
        }
    }
    //cout << "n-N" << n-N << endl;
    if(n == N){
        for(int j =1;j<=i;j++){
            printf("%d\n",j);
        }
        return 0;
    }
    int s = n - N;
    for(int j =1;j<=i;j++){
        if(j == s){
            continue;
        }
        printf("%d\n",j);
    }


    return 0;
}
