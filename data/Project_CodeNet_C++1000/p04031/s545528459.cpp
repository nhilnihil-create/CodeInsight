#include <bits/stdc++.h>
using namespace std;

int getCost(int a, int b){
    return pow(a-b,2.0);
}

int main()
{
    int N;
    cin >> N;
    int input[N];
    int minCost = 10000*N;

    for(int i=0; i<N; i++){
        cin >> input[i];
    }

    for(int i=-100; i <= 100; i++){
        int cost = 0;
        for(int j=0; j<N; j++){
            cost = cost + getCost(input[j], i);
        }
        if(cost < minCost){
            minCost = cost;
        }
    }
    cout << minCost << endl;
    return 0;
}