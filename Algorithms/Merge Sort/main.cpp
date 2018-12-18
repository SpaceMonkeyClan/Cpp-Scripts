// Merge Sort Algorithm - V 1.0.0
// Author: Dena, Rene
// Last Modified: 4/6/18

//________________________________________Misc._____________________________________________________

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//________________________________________Functions_________________________________________________

//MERGE SORT IMPLEMENTATION
// merge function
vector<int> merge(vector<int> left,vector<int> right){
    int leftCount = 0;
    int rightCount = 0;

    vector<int> results;

    bool useLeft;
    for (int i=0; i<left.size()+right.size();i++){
        if(leftCount<left.size()){
            if(rightCount<right.size()){
                useLeft = (left[leftCount] < right[rightCount]);
            }
            else{
                useLeft = true;
            }
        }
        else{
            useLeft = false;
        }
        if (useLeft){
            results.push_back(left[leftCount]);
            if (leftCount < left.size()){
                leftCount++;
            }
        }
        else{
            results.push_back(right[rightCount]);
            if (rightCount<right.size()){
                rightCount++;
            }
        }
    }

    cout << "\n\nWorking on it.......!" << endl;
    cout << "\n\nSorted output: " << endl;
    cout << "[ ";
    copy(results.begin(), results.end(), ostream_iterator<int>(cout, " "));
    cout << "] ";

    return results;
}

// merge sort function
vector<int> mergeSort(vector<int> arr){
    if (arr.size() <= 1){
        return arr;
    }
    int len = floor(arr.size()/2);
    vector<int> left(arr.begin(), arr.begin()+len);
    vector<int> right(arr.begin()+len, arr.end());

    return merge(mergeSort(left),mergeSort(right));
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
int main(){
    cout << "\n\t\t\tWelcome to the \"Merge Sort\' Algorithm" << endl;

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

    cout << "\n\nWe will now work our magic and sort your input your values by  numerical order into a list for you using the \'Merge Sort\' method." << endl;
    cout << "We will also identify the MEAN, MEDIUM, and MODE of that ordered list." << endl;
    cout << "Lets do that now! :)" << endl;

    vector<int> msort = mergeSort(myVector);

    int myArray[10] = {};
    memcpy( myArray, &myVector[0], sizeof( int ) * myVector.size() );

    int x = sizeof(myArray)/sizeof(myArray[0]);
    cout << "\nThe Mean = " << arrayMean(myArray, x) << endl;
    cout << "The Median = " << arrayMedian(myArray, x) << endl;
    cout << "The Mode = " << arrayMode(myArray, x) << endl;
}
