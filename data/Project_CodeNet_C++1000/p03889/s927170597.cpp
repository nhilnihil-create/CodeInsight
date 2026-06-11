#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)

//  鏡文 Mirror String.cpp
//
//  Created by WinnieJt on 2019/3/21.
//
//  Copyright © 2019 金天. All rights reserved.

//åß∂ƒ∆Ω≈µç∫πø∑¢∞§¶

#include<bits/stdc++.h>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cerrno>
#include<clocale>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<utility>
#include<vector>
#include<cwchar>
#include<cwctype>
typedef double db;
typedef std::string str;
typedef long long ll;
using namespace std;
str s;
str f;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    f=s;
    std::reverse(s.begin(),s.end());
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='b') s[i]='d';
        else if(s[i]=='d') s[i]='b';
        if(s[i]=='p') s[i]='q';
        else if(s[i]=='q') s[i]='p';
    }
    if(s==f) cout << "Yes" << endl;
    else cout<<"No"<<endl;
    return 0;
}
