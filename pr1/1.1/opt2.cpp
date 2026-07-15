#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,h;
    cin >> n;
    cin >> h;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << endl;

    int rot[n];

    for(int i=0;i<n;i++)
   {
  
        rot[i]=a[(i+h)%n];
   }

    for(int i=0;i<n;i++)
    {
        cout << rot[i] << endl;;
    }    
}