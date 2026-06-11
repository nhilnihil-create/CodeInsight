#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

//https://atcoder.jp/contests/abc068/tasks/abc068_b

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    //linjen er opp til 100. det er en linje p[ lengde hundre med hus p[ bare de nevte stedene]]

    int n;
    std::cin >> n;

    int res = 1;
    while (res <= n)
    {
        res = res * 2;
    }
    res = res / 2;

    std::cout << res << "\n";
}
