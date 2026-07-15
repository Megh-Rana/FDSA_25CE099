#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    int count=0,maxcount=INT_MIN;
    while (cin.get(ch)) {
        if(ch!=' ')
        {
            count++;
        }
        else
        {
            maxcount=max(count,maxcount);
            count=0;
        }
    }
    cout << maxcount;
}