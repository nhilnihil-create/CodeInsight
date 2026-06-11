#include <iostream>
#include <cstdio>

using namespace std;


class Rectangle{

private:
    int minx, maxx, miny, maxy;

public:
    Rectangle(int W, int H) : minx(0), miny(0), maxx(W), maxy(H){}

    void op(int x, int y, int a){

        if(a == 1) minx = max(minx, x);
        else if(a == 2) maxx = min(maxx, x);
        else if(a == 3) miny = max(miny, y);
        else maxy = min(maxy, y);
    }

    int area(){
        return max(0, (maxx - minx)) * max(0, (maxy - miny));
    }
};

int main() {

    int W, H, N;
    scanf("%d%d%d", &W, &H, &N);

    Rectangle rec(W, H);
    int x, y, a;
    while(N --){
        scanf("%d%d%d", &x, &y, &a);
        rec.op(x, y, a);
    }
    printf("%d\n", rec.area());

    return 0;
}
