#include<bits/stdc++.h>
using namespace std;
//bool compare(string a, string b){
//   // cout << "compare(" << a << "," << b << ")" << endl;
//    return (a.compare(b) < 0);
//}
int main()
{
    int n,l;
    cin>>n>>l;
    vector<string>vs;
    string tem;
    for(int i=0;i<n;i++)
    {
        cin>>tem;
        vs.push_back(tem);
    }
    sort(vs.begin(),vs.end());
//    for(int i=0;i<l;i++)
//    {     tem=vs[i];
//        for(int j=i+1;j<l;j++)
//        {
//           if(tem.compare(vs[j])<=0)
//           {
//
//           }
//           else
//           {
//               tem=vs[j];
//           }
//
//        }
//        cout<<tem;
//    }
    for(int i=0;i<n;i++)
    {
        cout<<vs[i];
    }


    cout<<"\n";


return 0;}
