#include <bits/stdc++.h>
using namespace std;
int cnt=0;

int find_iterative(vector<int> nums,int target)
{
    int left=0,right=nums.size()-1,mid;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        cnt++;
        if(target==nums[mid])
        {
            return mid;
        }
        else if(target<nums[mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return -1;
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

    int result=find_iterative(roll_numbers,roll_no_tosearch);
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