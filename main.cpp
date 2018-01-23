#include <iostream>

void selectionSort(std::string &a){
    //This function will sort an array, using ASCII values.
    //In this assignment, all the spaces of an anagram will go to the front, with the characters in the back.

    bool swapped;   //swapped for sorting method
    do{
        swapped = false; //bool is false
        for(int i = 0; i <= a.length();  i++)
            //For loop iterattes over length of a, swapping one character with another until
            //there is an iteration without doing one swap
        {
            if ((a[i] > a[i+1]) && (i+1 < a.length()))
                //Swap will occur if the intended character is greater alphabetically than the subsequent one.
                //Second comparison in if statement prevents comparing the last letter of the string with a memory address out of bounds
            {
                char temp = a[i]; //temp variable to store the character that will be swapped
                a[i] = a[i+1];    //current subsequent index is copied into the current index
                a[i+1] = temp;    //subsequent index is set to temp (the previous value)
                swapped = true;   //boolean for the final check
            }
        }
    }while(swapped);
}


void deleteSpaces(std::string &a){
    //Given that the string is already sorted, with spaces in the front and characters in the back,
    //this function will find the first instance of a character, and delete everything before it.

    int index = 0;  //Temporary variable to store index of first character
    for(int i = 0; i < a.length(); i++){ //For loop will iterate through length of string
        if (a[i] >= 'A') {
            //When the first character is found, we will store the index and break from the loop
            index = i;
            break;
        }
    }
    a.erase(0,index);
    //Everything from the beginning to the first index will then be deleted.
}


int main() {

    std::string a,b;     //Two strings to be compared

    std::cout << "Please enter the first string in lowercase and without punctuation: "; //Input 1st string
    std::getline(std::cin, a);

    std::cout << "Please enter the second string in lowercase and without punctuation: ";//Input 2nd string
    std::getline(std::cin, b);


    selectionSort(a); //We first sort the two strings.
    selectionSort(b);

    deleteSpaces(a); //Then we delete the spaces inside each string
    deleteSpaces(b);

    if (a == b){    //After we have gotten rid of the spaces and sorted the string, we can call it an anagram if they are equal
                    //They will only be equal if they have the exact same characters and length
       std::cout << "The two are an anagram pair" << std::endl;
    }
    else            //If the two fail the comparison, they are not anagrams
       std::cout << "The two are not an anagram pair" << std::endl;
}
