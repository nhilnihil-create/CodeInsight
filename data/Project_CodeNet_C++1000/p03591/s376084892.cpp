#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;


char str[20]={0};
int main(int argc, char* argv[])
{
    scanf("%s", str);
    str[4]='\0';
    if(strcmp(str,"YAKI")==0) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }



    return 0;
}
