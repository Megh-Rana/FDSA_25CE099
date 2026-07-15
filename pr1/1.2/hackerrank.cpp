#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
//    unordered_map<int, int> freq;
      map<int, int> freq;
    for (int i=0; i<n; i++) {
        freq[a[i]]++;
    }
    int count=0;
    for (auto& it : freq) {
        if(it.second==2)
        {
            cout << it.first << " ";
            count++;
        }
    }    
    if(count==0)
    {
        cout << -1;
    }
}