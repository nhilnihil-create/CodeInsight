#include <iostream>
#include <vector>

using namespace std;

const int INF = 1231231234;

struct pt
{
    int x, y, type;

    pt(){}
    pt(int a, int b, int c = 0) : x(a), y(b), type(c) {}
    int dist(pt o)
    {
        return !type ? abs(x - o.x) + abs(y - o.y) : max(abs(x - o.x), abs(y - o.y));
    }
};

pt toChebyshev(pt p)
{
    return {p.x + p.y, p.x - p.y, 1};
}

pt toManhattan(pt p)
{
    return {(p.x + p.y) / 2, (p.x - p.y) / 2, 0};
}

char getColor(pt p, int minx, int miny, int d)
{
    int xPartition = (p.x - minx + 1) / d, yPartition = (p.y - miny + 1) / d;
    if (xPartition & 1)
    {
        return yPartition & 1 ? 'R' : 'B';
    }
    else
    {
        return yPartition & 1 ? 'G' : 'Y';
    }
}

int main()
{
    int h, w, d;
    cin>>h>>w>>d;

    vector <pt> corners = {{0, 0}, {h, 0}, {0, w}, {h, w}}, converted(4);
    int minX = INF, maxX = -INF, minY = INF, maxY = -INF;
    for (int i = 0; i < 4; i++)
    {
        converted[i] = toChebyshev(corners[i]);
        minX = min(minX, converted[i].x), maxX = max(maxX, converted[i].x);
        minY = min(minY, converted[i].y), maxY = max(maxY, converted[i].y);
    }

    char grid[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            pt p = toChebyshev({i, j});
            grid[i][j] = getColor(p, minX, minY, d);
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout<<grid[i][j];
        }
        cout<<'\n';
    }



    return 0;
}
