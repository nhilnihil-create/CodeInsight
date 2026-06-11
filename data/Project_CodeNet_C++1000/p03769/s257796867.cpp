
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

ll n;
vector<int> vec;
deque<int> dq;

int main() {
    scanf("%lld",&n);
    while (n>0) {
    	if (n%2==1) {
    		vec.pb(1);
    		n=(n-1)/2;
    	} else {
    		vec.pb(0);
    		n--;
    	}
    }
    int len=vec.size();
    for (int i=len-1;i>=0;i--) {
    	if (vec[i]==0) {
    		dq.push_front(len-i);
    	} else {
    		dq.push_back(len-i);
    	}
    }
    printf("%d\n",2*len);
    for (int i=0;i<len;i++) {
    	printf("%d ",i+1);
    }
    for (int i:dq) printf("%d ",i);
    printf("\n");
}
