#include <iostream>

using namespace std;

int main()
{
    string N;
    cin >> N;
    int num = stoi(N);
    int *aN = new int[num];
    string a;
    int inNum;
    for(int i = 0; i < num; ++i)
    {
        cin >> a;
        inNum = stoi(a);
        aN[i] = inNum;
    }
    int result;
    int temp;
    int counter = 0;
    for(int i = -100; i <= 100; ++i)
    {
        for(int n = 0 ; n < num ; n++)
        {
            temp += (aN[n] - i)* (aN[n] -i);
        }
        if(counter == 0)
        {
            result = temp;
        }
        if(result > temp)
            result = temp;
        temp = 0;
        counter++;
    }
    cout << result << endl;
}
