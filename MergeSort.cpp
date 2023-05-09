#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N];
int Noc=0;
void merge(int l,int r,int mid)
{
    int l_size=mid-l+1;
    int left_arr[l_size+1];
    int r_size=r-mid;
    int right_arr[r_size+1];

    for(int i=0;i<l_size;i++)
    {
        left_arr[i]=a[i+l];
    }
    for(int i=0;i<r_size;i++)
    {
        right_arr[i]=a[i+mid+1];
    }

    //special 

    left_arr[l_size]=right_arr[r_size]=INT_MAX;

    int l_ind=0;
    int r_ind=0;
    for(int i=l;i<=r;i++)
    {
        if(left_arr[l_ind]<=right_arr[r_ind])
        {
            a[i]=left_arr[l_ind];
            l_ind++;
        }
        else
        {
            a[i]=right_arr[r_ind];
            r_ind++;
        }
        Noc++;
    }
    
}
void mergeSort(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);

    merge(l,r,mid);

}
int main()
{
    int t=100;
    srand(time(0));
    ofstream outdata;
    ofstream outdata2;
    outdata.open("Mergesort.txt");
    outdata2.open("MergesortComparison.txt");
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
        a[i]=x;
    }
    cout<<endl;
    outdata<<endl;
    mergeSort(0,n-1);
    cout<<"\n\tSorted array\n\n";
    outdata<<"\n\nS O R T E D   A R R A Y\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<< " , ";
        outdata<<a[i]<< " , ";
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

    // outdata2<<"\t"<<100-t<<"\t"<<n<<"\t"<<Noc<<"\t"<< fixed<<time_taken << setprecision(5)<<"\n";
    // outdata2<< fixed<<time_taken << setprecision(5)<<",";
    outdata2<< Noc<<",";
    Noc=0;
    cout<<"\n------------------------------------------ -------------------------------------------------------------------------------\n\n";
    outdata<<"\n-------------------------------------------------------------------------------------------------------------------------\n\n";

    }

    outdata.close();
}