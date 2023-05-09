#include<iostream>
 using namespace std;
 int  count=0; /* to count the number of comparisions */

 int merge( int arr [ ], int l, int m, int r)
{
 int i=l; /* left subarray*/
 int j=m+1; /* right  subarray*/
 int k=l; /* temporary array*/
 int temp[r+1];
 while( i<=m && j<=r)
 {
   if ( arr[i]<= arr[j])
  {
    temp[k]=arr[i];
    i++;
  }
   else
  {
    temp[k]=arr[j];
    j++;
  }
    k++;
    count++;

  }
   while( i<=m)
  {
    temp[k]=arr[i];
    i++;
    k++;
  }
    while( j<=r)
  {
    temp[k]=arr[j];
    j++;
    k++;
  }
  for( int p=l; p<=r; p++)
  {
    arr[p]=temp[p];
  }
   return count;
  }


  int  mergesort( int arr[ ], int l, int r)
  {
    int comparisons;
    if(l<r)
  {
   int m= ( l+r)/2;
   mergesort(arr,l,m);
   mergesort(arr,m+1,r);
   comparisions = merge(arr,l,m,r);
  }
   return comparisons;
  }

 int main ()
 {
   int size;
   cout<<" Enter the size of an array "<< endl;
   cin>>size;
   int myarr[size];
   cout<<"  Enter the elements of array "<<endl;
   for ( int i=0; i< size; i++)
 {
   cin>>myarr[i];
 }
 cout<<"  Elements of array before sorting are  "<<endl;
 for ( int i=0; i< size; i++)
 {
   cout<<myarr[i]<<"  " ;
 }
  cout<<endl;
  int c=mergesort(myarr, 0, size-1);
  cout<<"  Elements of array after sorting are  "<<endl;
  for ( int i=0; i< size; i++)
 {
   cout<<myarr[i]<<"  " ;
 }
   cout<<endl;
   cout<<"  Number of comaprisions while sorting the given array"<< c <<endl;
   return 0;
 }
// 169


//  929 370 69 425 84 360 378 144 357 425 919 963 883 602 739 582 761 271 268 147 691 361 311 360 986 510 829 787 229 483 583 280 174 215 927 520 828 473 731 881 925 991 926 813 266 58 328 239 127 932 118 448 654 587 277 807 55 277 646 675 889 827 64 659 95 345 559 774 54 213 59 840 166 136 966 665 251 649 493 610 926 420 295 804 679 680 536 821 519 340 828 492 970 564 948 80 666 810 354 619 555 289 405 471 86 878 589 970 749 963 157 494 855 616 521 660 350 436 846 907 300 846 614 877 435 677 480 889 859 845 287 390 67 677 634 834 332 571 175 634 969 276 330 63 767 520 565 980 87 738 512 217 612 326 586 940 841 419 374 973 786 888 57 136 441 279 430 162 259 