//ABC042 2020-8-3
#include<iostream>

bool is_575(int a, int b, int c);
void swap(int& a, int& b);
int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if(is_575(a, b, c)){
        std::cout << "YES\n";
    }else{
        std::cout << "NO\n";
    }
    return 0;
}

bool is_575(int a, int b, int c)
{
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    return (a == 5 && b == 5 && c == 7);
}

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
