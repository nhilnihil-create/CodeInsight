#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
    int K, S;
    cin >> K >> S;
    
    int count=0;
    for(int x = 0; x <= K; x++){
        for(int y = 0; y <= K; y++){
                if(S - (x + y) >= 0 && S - (x + y) <= K) count++;
        }
    }
 
    cout << count << endl;
}