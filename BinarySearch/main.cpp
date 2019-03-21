#include <iostream>
using namespace std;

int binarySearch(int* arr, int n, int x, int begin, int end);

int main()
{
    int arr[12] = {12, 2, 54, 1, 3, 4, 16, 13, 10, 24, 22, 30};
    int idx = binarySearch(arr, 12, 30, 0, 11);
    cout << idx << endl;
    return 0;
}

int binarySearch(int *arr, int n, int x, int begin, int end)
{
    if (begin == end)
    {
        if (arr[begin] == x)
            return begin;
        return -1;
    }

    int mid = (begin + end) / 2;
    if (arr[mid] == x)
        return mid;
    int left = binarySearch(arr, n, x, begin, mid);
    int right = binarySearch(arr, n, x, mid + 1, end);
    if (left >= 0)
        return left;
    return right;
}
