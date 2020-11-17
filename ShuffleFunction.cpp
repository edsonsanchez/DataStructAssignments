#include <iostream>
#include <vector> 
#include <ctime>
using namespace std;

// Function Declaration
void shuffleFunc(int);

int main(){
    shuffleFunc(10);
    return 0;
}

//Function Definition
void shuffleFunc(int v){
    int array[v];
    int r;

    srand(time(NULL));

    cout<<"Unshuffled: ";
    
    for (int j=0; j<v; j++){ // creating the array
        array[j] = j+1;
        cout<<array[j]<<' ';  //printing the unshuffled array
    }   

    for (int i = v-1 ; i >= 0; i--){ //setting i to start from the last position and go down

        r=rand()%(i+1);              // getting the random integer in the range 0..i

        swap(array[i],array[r]);     //moving the positions of the values     
    }

    cout<<"\nShuffled: ";

    for (int j=0;j<v;j++){  //printing the shuffled array
        cout<<array[j]<<' ';
    }

}