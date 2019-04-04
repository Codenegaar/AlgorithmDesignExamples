#include <iostream>
using namespace std;

int maximumSubarray(int* arr, int start, int end);
void printArray(int* arr, int n);

int main()
{
    int arr[9] = {-4, 5, -2, -2, 6, -4, 3, -4, 4};
    printArray(arr, 9);
    int max = maximumSubarray(arr, 0, 8);
    cout << "Max sum subarray: " << max << endl;
    return 0;
}

int maximumSubarray(int *arr, int start, int end)
{
    if (start == end)
        return arr[start];

    int mid = (start + end) / 2;
    int l = maximumSubarray(arr, start, mid);
    int r = maximumSubarray(arr, mid + 1, end);

    int maxLeft;
    int temp = 0;
    bool flag = true;   //checks if maxLeft is initialized

    for (int i = mid; i >= start; i--)
    {
        temp += arr[i];
        if (flag || temp > maxLeft)
            maxLeft = temp;
        flag = false;
    }

    temp = 0;
    flag = true;
    int maxRight;
    for (int i = mid + 1; i <= end; i++)
    {
        temp += arr[i];
        if (flag || temp > maxRight)
            maxRight = temp;
        flag = false;
    }

    if (l >= r && l >= (maxLeft + maxRight))
        return l;
    if (r >= l && r >= (maxLeft + maxRight))
        return r;
    return maxLeft + maxRight;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << ", ";
        cout << arr[i];
    }
    cout << endl;
}
