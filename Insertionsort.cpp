// C++ program for insertion sort

#include <bits/stdc++.h>
using namespace std;
int a[1000];
int Noc=0;
// Function to sort an array using
// insertion sort
void insertionSort(int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
            Noc++;
		}
		a[j + 1] = key;
	}
}

int main()
{
    int t=100;
    srand(time(0));
    ofstream outdata;
    ofstream outdata2;
    outdata.open("Insertionsort.txt");
    outdata2.open("InsertionSortComparison.txt");
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
    int lb = 0, ub = 5000;
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
        a[i]=x;
    }
    cout<<endl;
    outdata<<endl;
	insertionSort(n);
    cout<<"\n\tSorted array\n\n";
    outdata<<"\n\nS O R T E D   A R R A Y\n\n";
	for (int i = 0; i < n; i++)
    {
		cout << a[i] << " , ";
		outdata << a[i] << " , ";
    }
	cout << endl;
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
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n\n";
    outdata<<"\n-------------------------------------------------------------------------------------------------------------------------\n\n";

    }

    outdata.close();

}
// This is code is contributed by rathbhupendra
