#include<bits/stdc++.h>


int main()
{
    long long h,w,hh,ww;
    std::cin >> h >> w;
    long long ws = w / 3;
    long long min = 1000000000;
    for(long long i = 0; i  < 2; i++){
        ww = w - ws;
        long long a,b,c;
        a = h * ws;
        b = h * (ww / 2);
        c = h * ((ww + 2 - 1)/2);
        min = std::min(std::max(std::abs(a - b),std::max(std::abs(b - c),std::abs(c - a))),min);
        a = h * ws;
        b = ww * (h / 2);
        c = ww * ((h + 2 - 1) / 2);
        min = std::min(std::max(std::abs(a - b),std::max(std::abs(b - c),std::abs(c - a))),min);
        ws = (w + 3 - 1) / 3;
    }

    long long hs = h / 3;
    for(long long i = 0; i < 2; i++){
        hh = h - hs;
        long long a,b,c;
        a = w * hs;
        b = w * (hh / 2);
        c = w * ( (hh + 2 - 1) / 2 );
        //std::cerr << a << " : " << b << " : " << c << std::endl;
        min = std::min(std::max(std::abs(a - b),std::max(std::abs(b - c),std::abs(c - a))),min);

        a = w * hs;
        b = hh * (w / 2);
        c = hh * ((w + 2 - 1) / 2);
        min = std::min(std::max(std::abs(a - b),std::max(std::abs(b - c),std::abs(c - a))),min);
        hs = (h + 3 - 1) / 3;
    }
    std::cout << min << std::endl;


}
