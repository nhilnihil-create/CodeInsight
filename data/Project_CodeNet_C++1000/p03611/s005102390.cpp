#include <bits/stdc++.h>
using namespace std;

int main(){
    int data[100000];
    for(int i=0; i<100000; i++) data[i]=0;
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        data[tmp]++;
    }
    int maxCnt = 0;
    for (int i = 1; i < 99999; i++)
    {
        int sum = data[i-1]+data[i]+data[i+1];
        maxCnt = (maxCnt < sum) ? sum : maxCnt;
    }

    cout << maxCnt;
    
    
}