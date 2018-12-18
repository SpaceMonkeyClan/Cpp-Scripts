// Bubble Sort Algorithm - V 1.0.0
// Author: Dena, Rene
// Last Modified: 4/6/18


/**
 * To find the MEAN, add up the values in the data set and then divide by the number of values that you added.
 * To find the median, list the values of the data set in numerical order and identify which value appears in the middle of the list.
 * To find the mode, identify which value in the data set occurs most often.
 * */

//________________________________________Misc._____________________________________________________

#include <iostream>
#include <string>
#include <cassert>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

//________________________________________Functions_________________________________________________

//BUBBLE SORT IMPLEMENTATION
vector<int> bubbleSort(vector<int> arr){
    bool pass = false;
    int temp;

    while (!pass){
        pass = true;
        for (int i=0; i<arr.size()-1; i++){
            if (arr[i] > arr[i+1]){
                pass = false;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    cout << "\n\nWe will now work our magic and sort your input  values by numerical order into a list for you using the \'Bubble Sort\' method." << endl;
    cout << "We will also identify the MEAN, MEDIUM, and MODE of that ordered list." << endl;
    cout << "Lets do that now! :)" << endl;
    cout << "\n\nLOADING.......&nd DONE!" << endl;
    cout << "\n\nSorted output: " << endl;

    cout << "[ ";
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << "] ";

    return arr;
}

// Function for calculating mean
double arrayMean(int myArray[], int x) {
    int sum = 0;
    for (int i = 0; i < x; i++)
        sum += myArray[i];

    return (double)sum/(double)x;
}

// Function for calculating median
double arrayMedian(int myArray[], int x) {
    return (double)(myArray[(x-1)/2] + myArray[x/2])/2.0;
}

// Function for calculating mode
double arrayMode(int myArray[], int x) {
    int* ipRepetition = new int[x];
    for (int i = 0; i < x; ++i) {
        ipRepetition[i] = 0;
        int j = 0;
        while ((j < i) && (myArray[i] != myArray[j])) {
            if (myArray[i] != myArray[j]) {
                ++j;
            }
        }
        ++(ipRepetition[j]);
    }
    int iMaxRepeat = 0;
    for (int i = 1; i < x; ++i) {
        if (ipRepetition[i] > ipRepetition[iMaxRepeat]) {
            iMaxRepeat = i;
        }
    }
    delete [] ipRepetition;
    return myArray[iMaxRepeat];
}

//________________________________________All Script________________________________________________

// CALL SORT FUNCTIONS
int main() {
    cout << "\n\t\t\tWelcome to the \"Bubble Sort\' Algorithm!" << endl;

    vector<int> myVector;
    string name;

    cout << "\nIn starting, what is your name?: ";
    getline(cin, name);
    cout << "\nHello, " << name << ". Let us begin!\n" << endl;

    cout << "\nPlease ENTER ten integers......" << endl;
    int input;
    int i = 1;
    while (i <= 10) {
        cout << "Enter integer # " << i++ << ": ";
        cin >> input;
        myVector.push_back(input);
    }

    cout << "\nAwesome! You\'ve selected numbers: " << endl;
    cout << "[ ";
    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
    cout << "] ";

    vector<int> bsort = bubbleSort(myVector);

    // Convert Vector to an Array for workaround
    int myArray[10] = {};
    memcpy( myArray, &myVector[0], sizeof( int ) * myVector.size() );

    int x = sizeof(myArray)/sizeof(myArray[0]);
    cout << "\nThe Mean = " << arrayMean(myArray, x) << endl;
    cout << "The Median = " << arrayMedian(myArray, x) << endl;
    cout << "The Mode = " << arrayMode(myArray, x) << endl;
}
