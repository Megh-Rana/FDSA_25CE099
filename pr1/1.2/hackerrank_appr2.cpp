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

    unordered_map<int, int> freq;
    vector<int> result;

    for (int i=0; i<n; i++) {
        freq[a[i]]++;
        if (freq[a[i]] == 2) {
            result.push_back(a[i]);
        }
    }
    sort(result.begin(),result.end());
    if (result.empty()) {
        cout << -1;
    } else {
        for (int x : result) {
            cout << x << " ";
        }
    }
}