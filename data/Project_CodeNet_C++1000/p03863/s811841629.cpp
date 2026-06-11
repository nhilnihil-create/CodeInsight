#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)

//  ch.cpp
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
typedef long long ll;
using namespace std;
string inp;
int main(void)
{
    ios::sync_with_stdio(false);
    getline(cin,inp);
    if(inp[0]==inp[(inp.length())-1])
    {
        if((inp.length())%2==0) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    else
    {
        if((inp.length())%2==0) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    return 0;
}

