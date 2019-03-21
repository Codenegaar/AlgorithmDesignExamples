#include <iostream>
using namespace std;

/*!
 * \brief mergeSort Sorts the array using the merge sort algorithm
 * \param arr Array of integers to sort
 * \param start Start index of the subarray
 * \param end End index of the subarray
 * \return The sorted array
 */
int* mergeSort(int* arr, int start, int end);
void printArray(int* arr, int n);

int main()
{
    int arr[13] = {12, 2, 54, 1, 3, 4, 16, 13, 17, 10, 24, 22, 30};
    printArray(arr, 13);
    int* sortedArr = mergeSort(arr, 0, 12);
    printArray(sortedArr, 13);
    delete[] sortedArr;
    return 0;
}

//sorts a subarray of arr, starting from start and ending to (inclusively) end
int* mergeSort(int *arr, int start, int end)
{
    //Form a new array to merge the subarrays into
    int* b = new int[end - start + 1];
    if (start == end)
    {
        b[0] = arr[start];
        return b;
    }

    //find the index of the middle element
    int mid = (start + end) / 2;
    //sort the left subarray
    int* left = mergeSort(arr, start, mid);
    //sort the rightside subarray
    int* right = mergeSort(arr, mid + 1, end);

    //merge them into b
    int lIdx = 0;
    int lLength = mid - start + 1;
    int rIdx = 0;
    int rLength = end - (mid + 1) + 1;
    for (int k = 0; k <= end; k++)
    {
        //insert from the left subarray
        if (rIdx >= rLength || (lIdx < lLength && left[lIdx] <= right[rIdx]))
        {
            b[k] = left[lIdx];
            lIdx++;
        }
        else if (lIdx >= lLength || (rIdx < rLength && right[rIdx] < left[lIdx]))
        {
            b[k] = right[rIdx];
            rIdx++;
        }
    }
    return b;
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
