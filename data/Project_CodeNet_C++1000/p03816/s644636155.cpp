#include<bits/stdc++.h>


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int,int> map;
    for(int i = 0; i < n; i++)std::cin >> a[i];
    for(int i = 0; i < n; i++)map[a[i]]++;
    for(auto& i : map)while(i.second >= 3)i.second -= 2; // iは1または2である
    //2のとき次の2を探すもしなければ1つ引く
    int res = 0;
    int cnt = 0;
    for(auto i : map){
        res += i.second;
        if(i.second == 2)cnt++;
        std::cerr << i.first << " : " << i.second <<std::endl;
    }
    res -= 2 * ((cnt + 2 - 1) / 2);
    std::cout << res << std::endl;
}