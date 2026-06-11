#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

const int MAXN = 200001;

int chk(int A, int B, int C)
{
    int ans = 0;
    
    if (A==B && B==C && C==A && A%2==0)
        return -1;
    else if (A==B && B==C && C==A && A%2==1)
        return 0;
    
    while(true)
    {
        if((A%2==1) || (B%2==1) || (C%2==1))
        {
            return ans;
        }
        ans++;
        int a = (B + C) / 2;
        int b = (A + C) / 2;
        int c = (A + B) / 2;
        A = a; B = b; C = c;
    }

    return 0;
}

int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;
    int ans = chk(A, B, C);

    std::cout << ans << std::endl;
    return 0;
}