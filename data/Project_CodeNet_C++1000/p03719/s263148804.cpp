#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define N 5002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int a, b, c;
int main() {
	cin>>a>>b>>c;
    if (c >= a && c <= b) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}