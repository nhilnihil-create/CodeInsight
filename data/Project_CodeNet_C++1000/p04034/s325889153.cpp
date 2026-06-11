# include <iostream>
using namespace std;

int N;
int M;
int x[100005];
int y[100005];
pair<int, char> boxes[100005];
int counter=0;

int main()
{
    cin>>N>>M;
    
    for (int i=1; i<=M; i++)
    {
        cin>>x[i]>>y[i];
    }

    for (int i=1; i<=N; i++)
    {
        boxes[i].first=1;
        boxes[i].second='W';
    }

    boxes[1].second='R';



    for (int i=1; i<=M; i++)
    {
        boxes[x[i]].first--;
        boxes[y[i]].first++;
        if (boxes[x[i]].second=='R')
        {
            boxes[y[i]].second='R';
        }

        if (boxes[x[i]].first==0)
        {
            boxes[x[i]].second='W';
        }
    }   

    for (int i=1; i<=N; i++)
    {
        if (boxes[i].first>=1 && boxes[i].second=='R')
        {
            counter++;
        }
    }

    cout<<counter<<endl;
}