#include <iostream>
using namespace std;

void selectionSort(int* arr, int n);
void swap(int* arr, int a, int b);
void printArray(int *arr, int n);

int main()
{
    int arr[12] = {12, 2, 54, 1, 3, 4, 16, 13, 10, 24, 22, 30};
    printArray(arr, 12);
    selectionSort(arr, 12);
    printArray(arr, 12);
    return 0;
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        //range i -> n defines the sub-array to find minimum within
        int min = arr[i];
        int minIdx = i;
        for (int j = i; j < n; j++)
        {
            //find the minimum
            if (arr[j] < min)
            {
                min = arr[j];
                minIdx = j;
            }
        }
        //swap it with subarray's beginning
        swap(arr, i, minIdx);
    }
}

void swap(int* arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
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
