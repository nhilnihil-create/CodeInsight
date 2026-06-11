#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N = 0;
    cin >> N;
    for (long long i = pow(N,0.5); i>0 ; i--)
    {
        if (N%i==0)
        {
            //cout << i << endl;

            N = N/i;
            int ans = 0;
            while (true)
            {
                N /= 10;
                ans++;
                if (N==0)
                {
                    break;
                }
                
            }
            cout << ans  << endl;
            break;
            
            /* code */
        }
        //cout << i << endl;
        
    }
    


    return 0;
}