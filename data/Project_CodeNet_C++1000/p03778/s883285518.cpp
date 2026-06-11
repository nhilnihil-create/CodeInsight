#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int w, a, b, ans1 = 0, ans2 = 0;
    cin >> w >> a >> b;
    
    ans1 = b-(a+w);
    ans2 = a-(b+w);
    
    printf("%d\n", ans1 > ans2 ? ans1 > 0 ? ans1 : 0 : ans2 > 0 ? ans2 : 0);
    
    return 0;
}