#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int arr[10];
    for(int i=1;i<=3;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+1+3);
    if (arr[1]==5 && arr[2]==5 && arr[3]==7){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}