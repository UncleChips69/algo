#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int arr[N];
int Noc=0;
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (true) {

		// Find leftmost element greater than
		// or equal to pivot
		do {
			i++;
            Noc++;
		} while (arr[i] < pivot);

		// Find rightmost element smaller than
		// or equal to pivot
		do {
			j--;
            Noc++;

		} while (arr[j] > pivot);

		// If two pointers met
		if (i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}


int randomPivot(int arr[], int low, int high)
{
	// Generate a random number in between
	// low .. high
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high]
	swap(arr[random], arr[low]);

	return partition(arr, low, high);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = randomPivot(arr, low, high);
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

    
int main()
{
    int t=100;
    srand(time(0));
    ofstream outdata;
    ofstream outdata2;
    outdata.open("Quicksort.txt");
    outdata2.open("QuicksortComp.txt");
    outdata2<<"ITERATION NO.  |"<<"\t| I/P size\t"<<"\t| Comparisons\t"<<"\t| Time (sec)"<<endl<<endl;
    while(t--)
    {
    clock_t start, end;
    cout<<endl;
    outdata<<endl;
    outdata<<"\n-------------------------------------------------------------------------------------------------------------------------\n\n";
    cout<<"\tITERATION NO.-->"<<100-t<<"\n";
    outdata<<"\tITERATION NO.-->"<<100-t<<"\n";


    start = clock();
    int lb = 20, ub = 1000;
    int l=30,u=1000;
    int n=(rand() % (u - l + 1)) + l ;
    cout<<endl;
    cout<<"\tSize of array-->"<<n<<"\n\n";
    outdata<<endl;
    outdata<<"\tSize of array-->"<<n<<"\n\n";

	for(int i=0;i<n;i++)
    {
        int x=(rand() % (ub - lb + 1)) + lb;
        cout<<x<<" ";
        outdata<<x<<" ";
        arr[i]=x;
    }
    cout<<endl;
    outdata<<endl;

	quickSort(arr, 0, n - 1);
    cout<<"\n\tSorted array\n\n";
    outdata<<"\n\nS O R T E D   A R R A Y\n\n";

for (int i = 0; i < n; i++)
    {
    cout<<arr[i]<<" , ";
    outdata<<arr[i]<< " , ";

    }

      cout<<"\n\nTOTAL NUMBER OF COMPARISONS--> "<<Noc<<"\n\n";
    outdata<<"\n\nTOTAL NUMBER OF COMPARISONS--> "<<Noc<<"\n\n";
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by ITERATION "<<100-t<<" is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl<<endl;

    outdata << "Time taken by ITERATION "<<100-t<<" is : " << fixed
         << time_taken << setprecision(5);
    outdata << " sec " << endl<<endl;

    outdata2<<"\t"<<100-t<<"\t"<<n<<"\t"<<Noc<<"\t"<< fixed<<time_taken << setprecision(5)<<"\n";
    Noc=0;
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n\n";
    outdata<<"\n-------------------------------------------------------------------------------------------------------------------------\n\n";

    }

}
