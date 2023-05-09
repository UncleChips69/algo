// 4. Implement Radix Sort
// 5. Implement Bucket Sort
// // 6. Implement Randomized Select
#include <bits/stdc++.h>
using namespace std;

int random_partition(int *arr, int start, int end)
{
    srand(time(0));
    int pivotIdx = start + rand() % (end - start + 1);
    int pivot = arr[pivotIdx];
    swap(arr[pivotIdx], arr[end]); // move pivot element to the end
    pivotIdx = end;
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[pivotIdx]);
    return i + 1;
}

int random_selection(int *arr, int start, int end, int k)
{
    if (start == end)
        return arr[start];

    if (k == 0)
        return -1;

    if (start < end)
    {

        int mid = random_partition(arr, start, end);
        int i = mid - start + 1;
        if (i == k)
            return arr[mid];
        else if (k < i)
            return random_selection(arr, start, mid - 1, k);
        else
            return random_selection(arr, mid + 1, end, k - i);
    }
}
int main()
{
    int n;
    cout << "size of array-->";
    cin >> n;
    int A[n];
    int lb = 0, ub = 100;
    for (int i = 0; i < n; i++)
    {
        int x = (rand() % (ub - lb + 1)) + lb;
        cout << x << " ";
        A[i] = x;
    }
    cout << endl;
    // int k;
    // cout << "input k , kth smallest element-->";
    // cin >> k;
    cout<<endl;
    for(int i=1;i<8;i++)
    {
    int loc = random_selection(A, 0, n-1, i);
    cout << i << "th smallest element is " << loc;
    cout<<"\n\n";
    }
}
