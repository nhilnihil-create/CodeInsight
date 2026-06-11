#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

int arr[100005];
int memo[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    
    memset (arr, 0, sizeof (arr));
    memset (memo, 0, sizeof (memo));
    memo[1] = 1;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        
        arr[b]++;
        arr[a]--;
        
        if (memo[a] == 1)
            memo[b] = 1;
        if (arr[a] == -1)
            memo[a] = 0;
    }
    
    int cntr = 0;
    for (int i = 1; i <= n; i++){
        if (memo[i] == 1)
            cntr++;
    }
    cout << cntr << endl;
}

//1 2 3 4
//1 1 1 1
