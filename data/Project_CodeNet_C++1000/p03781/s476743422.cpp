#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//for(int i = 0; i<n; i++)
 
 
int main()
{
    int x;
    cin>>x;
    int i = 0;
    int sum = 0;
    while(1){
        i++;
        sum += i;
        if(sum >= x) break;
    }
    cout << i << endl;
    return 0;
    
}
