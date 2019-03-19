#include <iostream>
using namespace std;

void insertionSort(int* arr, int n);
void printArray(int* arr, int n);

int main()
{
    int arr[12] = {12, 2, 54, 1, 3, 4, 16, 13, 10, 24, 22, 30};
    printArray(arr, 12);
    insertionSort(arr, 12);
    printArray(arr, 12);
    return 0;
}

void insertionSort(int *arr, int n)
{
    //Iterate starting from the second element
    for (int i = 1; i < n; i++)
    {
        //Insertion range: 0 -> i-1
        int j = i - 1;
        int tmp = arr[i];
        while (j >= 0)
        {
            if (arr[j] > tmp)
            {
                //move jth element to right
                arr[j + 1] = arr[j];
            }
            else break;
            j--;
        }
        //j now points to the element smaller than ith element
        //insert ith element at index j + 1
        arr[j + 1] = tmp;
    }
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
