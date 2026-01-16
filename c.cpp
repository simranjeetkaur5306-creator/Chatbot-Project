#include <iostream>
using namespace std;
int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l;
    int j = h;
    while (i < j)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}
void quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int pivot = partition(a, l, h);
        quicksort(a, l, pivot - 1);
        quicksort(a, pivot + 1, h);
    }
}
int main()
{
    int size = 0;
    cout << "Enter the size:";
    cin >> size;
    int a[size];
    cout << "Enter the element:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout << "Before sorting:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << "";
    }
    quicksort(a, 0, (size - 1));
    cout << "\n After sorting:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << "";
    }
}