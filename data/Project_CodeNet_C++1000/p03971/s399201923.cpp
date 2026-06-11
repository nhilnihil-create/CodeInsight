#include <stdio.h>
#include <iostream>

//https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_b?lang=en

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    int N;
    std::cin >> N;

    int A;
    std::cin >> A;

    int B;
    std::cin >> B;

    int placesLeft = A + B;
    int overseasPlaces = B;

    char c;
    std::cin.get(c);
    for (int i = 0; i < N; i++)
    {
        std::cin.get(c);

        if (c == 'a')
        {
            if (placesLeft-- > 0)
            {
                std::cout << "Yes\n";
                continue;
            }
        }
        else if (c == 'b')
        {
            if (overseasPlaces-- > 0)
            {
                if (placesLeft-- > 0)
                {
                    std::cout << "Yes\n";
                    continue;
                }
            }
        }

        std::cout << "No\n";
    }
}
