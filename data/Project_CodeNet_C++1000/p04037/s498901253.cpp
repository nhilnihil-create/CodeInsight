#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>


using namespace std;
#define INF 1000000005
int main()
{
int n;
std::cin >> n;
std::vector<int> a;
for(int i = 0; i < n; i++){
    int tempa;
    std::cin >> tempa;
    a.push_back(tempa);
}
int twin = 0;
int pre = 0;
int flag = 0;
std::sort(a.begin(), a.end(), std::greater<int>());
for(int i = 0; i < n; i++){
    if(i == n - 1){
        flag = n - 1;
        break;
    }
    if(a[i] <= i + 1){
        flag = i;
        break;
    }
}
if(a[flag] == flag + 1){
    if(flag == n - 1){
        twin = 0;
    } else {
        int check = 0;
        for(int i = 1; i <= n - 1 - flag; i++){
            if(a[i + flag] < a[flag]){
                break;
            } else {
                check++;
            }
        }
        check = check % 2;
        if(check == 1){
            twin = 1;
        } else {
            twin = 0;
        }
    }
} else {
    if(a[flag] > flag + 1){
        twin = (a[flag] - flag + 1) % 2;
    } else {
        if(a[flag] == flag){
            int check = 0;
            for(int i = 1; i <= n - 1 - flag; i++){
                if(a[i + flag] < a[flag]){
                    break;
                } else {
                    check++;
                }
            }
            check = check % 2;
            if(check == 0){
                twin = 1;
            } else {
                twin = (a[flag - 1] - a[flag]) % 2; 
            }
        } else if((a[flag - 1] - flag) % 2 == 0){
            twin = 0;
        } else {
            twin = 1;
        }/*((a[flag - 1] - a[flag]) % 2 == 0){
            twin = 1;
        } else {
            twin = 0;
        } */
    }
}
if(twin == 1){
    std::cout << "First" << std::endl;
} else {
    std::cout << "Second" << std::endl;
}
return 0;
}