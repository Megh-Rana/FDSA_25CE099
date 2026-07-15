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

    for(int i=0;i<h;i++)
    {
        int last=a[0];
        for(int j=0;j<n;j++)
        {
            a[j]=a[j+1];
        }
        a[n-1]=last;
    }

    for(int i=0;i<n;i++)
    {
        cout << a[i] << endl;;
    }    
}