#include <stdio.h>
#include <iostream>
#include <vector>

//https://atcoder.jp/contests/abc074/tasks/abc074_b

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    //linjen er opp til 100. det er en linje p[ lengde hundre med hus p[ bare de nevte stedene]]

    int numberOfLines, lineLength;
    std::cin >> numberOfLines >> lineLength;

    int total = 0;
    for (int i = 0; i < numberOfLines; i++)
    {
        int location;
        std::cin >> location;
        total = total + 2 * std::min(location, lineLength - location);
    }

    std::cout << total << "\n";
}
