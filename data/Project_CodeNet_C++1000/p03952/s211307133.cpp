#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,x;
    scanf("%d %d", &n, &x);
    if(x == 1 || x == 2*n-1){
        printf("No");
        return 0;
    }
    vector<int> viAns;
    if(x == 2){
        for(int i = 3; i < n+1; i++){
            viAns.push_back(i); 
        }
        viAns.push_back(1); 
        viAns.push_back(2);
        for(int i = n + 1; i <= 2 * n - 1; i++){
            viAns.push_back(i); 
        }
        printf("Yes\n");
        for(int i = 0; i < 2 * n - 1; i++){
            printf("%d\n", viAns[i]);
        }
        return 0;
    }
    
    int i = 3;
    while(viAns.size() < n - 2){
        if(i != x && i != x + 1){
            viAns.push_back(i);            
        }
        i++;
    }
    viAns.push_back(1);
    viAns.push_back(x);
    viAns.push_back(x + 1);
    viAns.push_back(2);
    while(viAns.size() < 2 * n - 1){
        if(i != x && i != x+1){
            viAns.push_back(i);
        }
        i++;
    }    
    printf("Yes\n");
    for(int i = 0; i < 2 * n - 1; i++){
        printf("%d\n", viAns[i]);
    }
    return 0;
}
