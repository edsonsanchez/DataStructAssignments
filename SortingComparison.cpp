#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

const long int SORT_SIZE = 100000000;
long int arrSort[SORT_SIZE];

double getRand() {
  long int temp = ((long int)rand() << 12) |
                  ((long int)rand() & (long int)0x00000FFF);
  long int maxv = 0x0FFFFFFF; // 268435456
  return (double)temp / (double)maxv;
}


void merge(long int *array, long int l, long int m, long int r) {
   long int i, j, k, nl, nr;
   long int* larr;
   long int* rarr;
   //size of two temp arrays
   nl = m-l+1; 
   nr = r-m;
   //long int larr[nl], rarr[nr];
   larr = (long int*) malloc (nl*sizeof(long int));
   rarr= (long int*) malloc(nr*sizeof(long int));

   //fill temp arrays 
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   //moving to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //fill in rest of left
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //fill in rest of right
      array[k] = rarr[j];
      j++; k++;
   }
   free(larr);
   free(rarr);
}

void mergeSort(long int *array, long int l, long int r) {
   long int m;
   if(l < r) {
      long int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

void loadArray(){

  for(int i=0;i<SORT_SIZE;i++){
    arrSort[i]=(long int) (getRand() * 268435456.0);;
  }
}


int main(){

srand(time(NULL));
long int n = sizeof(arrSort)/sizeof(arrSort[0]); 

// C++ Sort
loadArray();
cout<< "Built-In Sort Time:";
auto start = chrono::high_resolution_clock::now();
sort(arrSort,arrSort+n);
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<milliseconds>(end - start);
cout << '\t' << float(duration.count())/1000.0 << " seconds"<<endl;


// BUBBLE SORT
/*  loadArray();
cout<<"Bubble Sort Time:";
auto start2 = chrono::high_resolution_clock::now();

 for(int j=0;j<n;j++){
    for(int i=0;i<n-1;i++){
        if(arrSort[i]>arrSort[i+1]){
          swap(arrSort[i],arrSort[i+1]);
        }
      }
    }

auto end2 = chrono::high_resolution_clock::now();
auto duration2 = chrono::duration_cast<milliseconds>(end2 - start2);
cout << '\t' << float(duration2.count())/1000.0 << " seconds"<<endl;  */


// Merge Sort
loadArray();
cout<<"Merge Sort Time:";
auto start3 = chrono::high_resolution_clock::now();

mergeSort(arrSort,0,n-1);

auto end3 = chrono::high_resolution_clock::now();
auto duration3 = chrono::duration_cast<milliseconds>(end3 - start3);
cout << '\t' << float(duration3.count())/1000.0 << " seconds"<<endl;



} // end main