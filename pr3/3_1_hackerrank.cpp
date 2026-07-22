#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int roll;
    int time;
};

int main()
{
    int n;
    cin >> n;

    vector<Student> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].roll >> arr[i].time;
    }

    int choice;
    cin >> choice;

    int swaps = 0;

    if(choice == 1) // Bubble Sort
    {
        for(int i = 0; i < n - 1; i++)
        {
            bool swapped = false;

            for(int j = 0; j < n - i - 1; j++)
            {
                if(arr[j].time > arr[j + 1].time)
                {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                    swapped = true;
                }
            }

            if(!swapped)
                break;
        }
    }
    else if(choice == 2) // Selection Sort
    {
        for(int i = 0; i < n - 1; i++)
        {
            int minIdx = i;

            for(int j = i + 1; j < n; j++)
            {
                if(arr[j].time < arr[minIdx].time)
                    minIdx = j;
            }

            if(minIdx != i)
            {
                swap(arr[i], arr[minIdx]);
                swaps++;
            }
        }
    }

    // Print sorted data
    for(int i = 0; i < n; i++)
    {
        cout << arr[i].roll << " " << arr[i].time << endl;
    }

    // Number of swaps
    cout << swaps << endl;

    // Top 2 students
    cout << arr[0].roll << "," << arr[1].roll << endl;

    return 0;
}
