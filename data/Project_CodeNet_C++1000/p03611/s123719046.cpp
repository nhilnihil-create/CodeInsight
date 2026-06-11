#include <bits/stdc++.h>
using namespace std;

int main(){
    int data[100000];
    for(int i=0; i<100000; i++) data[i]=0;
    
    int n;
    cin >> n;

    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        data[tmp]++;
        maxA = (maxA < tmp) ? tmp : maxA;
    }
    int maxCnt = 0;
    for (int i = 2; i < 100000; i++)
    {
        int sum = data[i-2]+data[i-1]+data[i];
        maxCnt = (maxCnt < sum) ? sum : maxCnt;
    }

    cout << maxCnt;
    
    
}