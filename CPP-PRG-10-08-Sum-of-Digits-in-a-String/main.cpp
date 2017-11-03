//
//  main.cpp
//  CPP-PRG-10-08-Sum-of-Digits-in-a-String
//
//  Created by Keith Smith on 11/2/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that asks the user to enter a series of single-digit numbers with nothing
//  separating them. Read the input as a C-string or a string object. The program
//  should display the sum of all the single-digit numbers in the string. For example, if the
//  user enters 2514, the program should display 12, which is the sum of 2, 5, 1, and 4.
//  The program should also display the highest and lowest digits in the string.
//

#include <iostream>
#include <cstring>

using namespace std;

const int INT_ARR_SIZE = 99;

char *getCharArray();
void sumNumbers(char *, int *, int *, int *);
void displayResults(char *, int *, int *, int *);

int main()
{
    char *chrArray = nullptr;
    
    int *intHigh = nullptr;
    intHigh = new int;
    *intHigh = INT_MIN;
    
    int *intLow = nullptr;
    intLow = new int;
    *intLow = INT_MAX;
    
    int *intSumNumbers = nullptr;
    intSumNumbers = new int;
    
    chrArray = getCharArray();
    
    sumNumbers(chrArray, intHigh, intLow, intSumNumbers);
    
    displayResults(chrArray, intSumNumbers, intHigh, intLow);
    
    return 0;
}

char *getCharArray()
{
    int *intArrSize = nullptr;
    intArrSize = new int;
    *intArrSize = INT_ARR_SIZE;
    
    char *chrArr = nullptr;
    chrArr = new char[*intArrSize];
    
    cout << "Please enter a series of up to 99 numbers:\n";
    cin.getline(chrArr, *intArrSize);
    
    return chrArr;
}

void sumNumbers(char *chrArr, int *intHigh, int *intLow, int *intSum)
{
    int *intArrSize = nullptr;
    intArrSize = new int;
    *intArrSize = INT_ARR_SIZE;
    
    int *intTemp = nullptr;
    intTemp = new int;
    
//    int *intSum = nullptr;
//    intSum = new int;
//    *intSum = 0;
    
    char *chrTemp = nullptr;
    chrTemp = new char;
    
    for (int i = 0 ; i < *intArrSize ; i++)
    {
        *chrTemp = chrArr[i];
        
        if (*chrTemp == '\0')
        {
            break;
        }
        
        *intTemp = atoi(chrTemp);
        
        *intSum += *intTemp;
        
        if (*intTemp < *intLow)
        {
            *intLow = *intTemp;
        }
        
        if (*intTemp > *intHigh)
        {
            *intHigh = *intTemp;
        }
    }
}

void displayResults(char *chrArr, int *intSum, int *intHigh, int *intLow)
{
    int i = 0;
    
    cout << "The sum of ";
    
    while(chrArr[i] != '\0')
    {
        cout << chrArr[i];
        i++;
    }
    
    cout << " is " << *intSum << endl;
    cout << "The lowest number was: " << *intLow << endl;
    cout << "The highest number was: " << *intHigh << endl;
}
