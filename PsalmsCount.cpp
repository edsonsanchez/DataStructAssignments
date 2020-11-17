// Code to count the number of times each character appears in the book of Psalms
// Starts counting after the tab that follows the verse name

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string textHold;  // string to hold inital line from txt
    int ascii[127]={};  // array to count # of times character appears, index num represents ascii val 
    int counter = 0;  // counter for lines processed
    char delim='\t';  // variale to hold delimiter

    ifstream textFile("bible-psalms.txt");  // opening the file

    while(getline (textFile,textHold)){  // while loop to get line by line into textHold
        int position = textHold.find_last_of(delim); // finding position of last tab in a line
        string newHold = textHold.substr(position+1);  // position+1 so it grabs everything after the tab position

        for(int i=0;i<=newHold.size();i++){  //for loop to look through each character in a line
            int asc = (int)newHold[i];  // getting the ascii value of the character
            ascii[asc]+=1;  // adding 1 to the array position of the character just read            
        }
        counter++; // increment counter everytime a line is done
    }

    for(int i =32;i<127;i++){  // for loop to output results , starts at 32 for 0x20
        if(ascii[i]>0){  // only outputting characters that show up once or more
            char character = (char)i;  // taking ascii value and converting to character
            if(character==' '){  // if statement to print out SPACE instead of an actual space
                cout<<"There are " << ascii[i]<< " instances of "<<"SPACE"<< " in the book of Psalms." <<endl;
            }else{        
                cout<<"There are " << ascii[i]<< " instances of "<<character<< " in the book of Psalms." <<endl;  // printing number of times the character appears
            }
        }
    }
    cout<<"Lines Processed: "<< counter;  // printing amount of lines processed
        
    textFile.close();  // closing the file
    return 0;
}
