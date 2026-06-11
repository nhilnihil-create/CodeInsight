//
//  main.cpp
//  test130
//
//  Created by  on 2019/06/16.
//  Copyright © 2 All rights reserved.
//
//
//  main.cpp
//  new
//
//  Created on 2019/06/09.
//  Copyright  All rights reserved.
//

// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif


#define f(i,n) for(int i=0;i<(n);i++)


#define inf (int)(3e18)
#define int long long
#define mod (int)(1000000007)
using namespace std;


int modpow(int x, int y, int m = mod) {
    int res = 1;
    while (y) {
        if (y % 2) {
            res *= x;
            res %= m;
        }
        x = x * x % mod;
        y /= 2;
    }
    return res;
}
bool prime(int x){
    for (int i=2; i<=sqrt(x); i++) {
        if (!(x%i)) {
            return false;
        }
    }
    return true;
}
double kyori(pair<int, int> f, pair<int, int> s){
    double ans=0;
    double t = fabs(f.first-s.first);
    double y = fabs(f.second-s.second);
    ans=sqrt(t*t+y*y);
    return ans;
}
int gcd(int x,int y){
    if (y==0) {
        return x;
    }
    return gcd(y,x%y);
}
int mypow(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) {
            res *= x;
        }
        x = x * x;
        y /= 2;
    }
    return res;
}

//void add(int i, int x){
//    while (i<=n) {
//        BIT[i] += x;
//        i += i & - i;
//    }
//}
//int sum(int i){
//    int s=0;
//    while (i>0) {
//        s += BIT[i];
//    }
//    return s;
//}

int n,a[100004],z,ans,ka,nor,amari;
string s;
vector<int> v;
signed main(){
    cin>>n;
    for (int i=0; i<n; i++) {
        int l;
        cin>>l;
        a[l]++;
    }
    
    for (int i=1; i<=100000; i++) {
        if (!a[i]) {
            continue;
        }
        int add=(a[i]-1)%2;
     
        amari+=max(0ll,add);
        ans++;
    }
    int nokoru=(amari)%2;
    
    ans-=nokoru;
    
    
    cout<<ans<<endl;
}


