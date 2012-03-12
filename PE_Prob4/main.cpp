//****************************
// Chris Engstrom            *
// Project Euler - Problem 4 *
//*******************************************************************
// Find the largest palindrome made from the product of             *
//  two 3-digit numbers.                                            *
//*******************************************************************

#include <iostream>
#include <time.h>

using namespace std;

// FUNCTION PROTOTYPES //
bool checkPalindrome(int num);      // Checks a number to see if it is a palindrome
int countDigits(int num);           // Counts the number of digits in a positive number

int main() {
        
    int a,                      // First factor to the palindrome
        b,                      // Second factor to the palindrome
        number,                 // Number calculated that will be checked
                                //  to see if it is a palindrome
        largestPali = -1;       // Store the largest palindrome so far

    cout << "This program finds the largest palindrome made from" << endl 
         << "the product of two 3-digit numbers." << endl << endl;

    // Loop through the first factor
    for(int i = 100; i < 1000; i++)
    {
        // Loop through the second factor
        for(int j = 100; j < 1000; j++)
        {
            // Calculate the number to check
            number = i * j;

            // Check to see if the number is a palindrome
            if(checkPalindrome(number)){
                // See if a largest palindrome already exists
                if(largestPali < 0) {
                    // If not, set the values
                    largestPali = number;
                    a = i;
                    b = j;
                } else {    // A largest palindrome exists
                    // Check to see if the current calculated number is
                    //	larger than the previous largest palindrome
                    if(number > largestPali) {
                        // If the calculated number is larger, set the values
                        largestPali = number;
                        a = i;
                        b = j;
                    }
                }
            }
        }
    }

    // Report the results
    cout << "The largest palindrome is: " << largestPali << endl << endl
         << "It's factors are: " << a << " x " << b << endl << endl;

    return 0;
}

//*******************************************************************************
// FUNCTION: bool checkPalindrome(int num)                                      *
//  int num - Number that will be checked to see if it is a palindrome          *
//                                                                              *
// RETURNS - Whether or not the number passed in is a palindrome                *
//*******************************************************************************
bool checkPalindrome(int num)
{
    bool isPali = true;                     // Return value, true until proven false
    int digitCount = countDigits(num);      // Number of digits in num
    char *possiblePali;                     // Pointer for char array equal to num
    
    // Assign a char array that the calculated number will fit in
    possiblePali = new char [digitCount + 1];

    // Assign the number to the char array as base 10
    itoa(num, possiblePali, 10);

    // Loop through the left side of the number as long as
    //  we know that it could be a palindrome
    for(int i = 0; (i < (digitCount / 2)) && isPali; i++)
    {
        // Check to see if the numbers are the same from
        //  the outside working in
        if(possiblePali[i] != possiblePali[(digitCount - 1) - i]) {
            // If the numbers aren't the same then the
            //  number passed in isn't a palindrome
            isPali = false;
        }
    }
    
    // Clean up dynamically allocated memory
    delete [] possiblePali;

    return isPali;
}

//*******************************************************************************
// FUNCTION: int countDigits(int num)                                           *
//  int num - The positive number we are counting the digits of                 *
//                                                                              *
// RETURNS - The number of digits in num                                        *
//*******************************************************************************
int countDigits(int num)
{
    // Start digit count at 0
    int count = 0;

    // Check for 0 case
    if(num == 0) {
        // Count is 1
        count++;
    } else {
        // Continue looping until num is less than 0
        while (num > 0) {
            // Divide the number by ten and save the result
            num /= 10;

            // Add one to the count
            count++;
        }
    }

    return count;
}