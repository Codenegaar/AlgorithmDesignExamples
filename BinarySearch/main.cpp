#include <iostream>
using namespace std;

/*!
 * \brief binarySearch Binary search algorithm implementation
 * \param arr Array of integers to search in
 * \param x Key to find
 * \param begin Begin index of the subarray
 * \param end End index of the subarray
 * \return Index of the key in the array, -1 if not found
 */
int binarySearch(int* arr, int x, int begin, int end);

int main()
{
    int arr[12] = {12, 2, 54, 1, 3, 4, 16, 13, 10, 24, 22, 30};
    int idx = binarySearch(arr, 30, 0, 11);
    cout << idx << endl;
    return 0;
}

int binarySearch(int *arr, int x, int begin, int end)
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
    int left = binarySearch(arr, x, begin, mid);
    int right = binarySearch(arr, x, mid + 1, end);
    if (left >= 0)
        return left;
    return right;
}
