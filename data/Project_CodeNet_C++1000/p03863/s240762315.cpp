#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <unordered_map>
#include <map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>
 
std::string s;
 
int main(void){
    std::cin >> s;

    if ((s.size() % 2 == 0 && s[0] == s[s.size()-1]) ||
        (s.size() % 2 == 1 && s[0] != s[s.size()-1])
    ) {
        std::cout << "First" << std::endl;
    } else {
        std::cout << "Second" << std::endl;
    }
    
    return 0;
}