#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int x, y;


int main(){
    scanf("%d%d", &x, &y);
    if(x < y) {printf("%d\n", min(y - x, abs(x + y) + 1)); return 0;}
  	if(x == 0 || y == 0) printf("%d\n", abs(x + y) + 1);
    else if(x < 0 && y > 0){
        printf("%d\n", abs(y + x) + 1);
    }
    else if(x > 0 && y < 0){
        printf("%d\n", abs( - y - x) + 1);
    }
    else printf("%d\n", x - y + 2);
}
