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

    int rotate[n];
    if(h>n)
    {
        h%=n;
    }  
    for(int i=0;i<n;i++)
   {
  
        rotate[i]=a[i+h];
   }
   int j=0;
   for(int i=h+1;i<n;i++)
   {
    rotate[i]=a[j++];
   }
    for(int i=0;i<n;i++)
    {
        cout << rotate[i] << endl;;
    }    
}