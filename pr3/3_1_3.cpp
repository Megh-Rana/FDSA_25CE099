#include <bits/stdc++.h>
using namespace std;

void sort_approach3(vector<int>& nums)
{
    int n = nums.size();

    for(int i = 1; i < n; i++)
    {
        int key = nums[i];
        int j = i - 1;

        while(j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    sort_approach3(nums);

    for(int x : nums)
        cout << x << " ";
}