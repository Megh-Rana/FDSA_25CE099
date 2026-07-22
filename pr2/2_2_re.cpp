#include <bits/stdc++.h>
using namespace std;
int cnt=0;

int find_recursive(vector<int> nums, int target, int left, int right)
{
    if(left > right)
    {
        return -1;
    }
    int mid = left + (right - left) / 2;
    cnt++;
    if(target == nums[mid])
    {
        return mid;
    }
    else if(target < nums[mid])
    {
        return find_recursive(nums, target, left, mid - 1);
    }
    else
    {
        return find_recursive(nums, target, mid + 1, right);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> roll_numbers(n);
    vector<int> submission_times(n);
    for(int i=0;i<n;i++)
    {
        cin >> roll_numbers[i] >> submission_times[i];
    }

    int roll_no_tosearch;
    cin >> roll_no_tosearch;

    int result=find_recursive(roll_numbers,roll_no_tosearch,0,roll_numbers.size()-1);
    if(result!=-1)
    {
        cout << submission_times[result] << endl;
        cout << cnt;
    }
    else
    {
        cout << "Not submitted" << endl;
    }
}