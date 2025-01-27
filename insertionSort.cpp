#include <bits/stdc++.h>
using namespace std;

//  { 10 , 9 , 8 ,  7 , 6 }
//     0   1   2    3   4

void insetionSort(vector<int> &arr)
{
    int key;
    int j;
    for (int i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    vector<int> arr(10);

    for (int i = 0; i < 10; i++)
        arr[i] = 10 - i;

    insetionSort(arr);

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";


    return 0;
}