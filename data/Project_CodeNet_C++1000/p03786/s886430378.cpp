#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[100005];
ll prefsum[100005];
int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    sort (arr+1, arr+n+1);
    
    for (int i = 1; i <= n; i++){
        if (i == 1)
            prefsum[i] = arr[i];
        else
            prefsum[i] = arr[i] + prefsum[i-1];
    }
    
    int cntr = 1;
    for (int i = n; i > 1; i--){
        if (2*prefsum[i-1] >= arr[i])
            cntr++;
        else{
            cout << cntr << endl;
            return 0;
        }
    }
    
    cout << cntr << endl;
    return 0;
}

//2 6 8 10 16 35 200
//2 8 16 26 42 77 277

//1 2 7 20 30 40
//1 3 10 30 60 100
//1 2 3  4   5;
