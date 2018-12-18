// Cluster Analysis Script - V 1.0.0
// Authors: Richard Tobing; James Bates; Rene Dena; Marty
// Last Modified: 5/8/18

/**
         +==================================== About The Script ============================================+
         | In the first part, the program asks the user how many cases (sets of numbers) they want to input |
         | along with the size of each cluster and the parameter k, which is the integer constant we use to |
         | compare each element in the cluster in order to know how to group them together. Based on how    |
         | many cases the user wants, the program loops that many times, and yields a different number      |
         | of clusters for each case                                                                        |
         +==================================================================================================+
*/

//__________________________________________________Misc._______________________________________________________________

#include <iostream>
#include <string>

using namespace std;

//__________________________________________________Main()______________________________________________________________

int main()
{
    int caseCnt;                                                          // Variable used to iterate # of cases in loop
    int caseNum;                                                          // Variable denoting the total number of cases

    cout<< "\nEnter number of cases: ";
    cin>> caseNum;

    for(caseCnt=1; caseCnt<=caseNum; caseCnt++)
    {
        int clusterNum = 1;
        int setSize;                                                      // Variable denoting the set size of the case
        int k;                                                            // Variable denoting the clustering parameter

        cout << "\n\t\t\t---------------> CASE #" << caseCnt << " <---------------" << endl;
        cout << "\nEnter the set size for case " << caseCnt << ": ";
        cin >> setSize;
        cout << "Enter clustering parameter for case " << caseCnt << ": ";
        cin >> k;
        cout << "\n" << endl;


                                                                             /** For each case the user is asked to input
                                                                             * an arbitrary number of elements which
                                                                             * will be put into an array via for loop.
                                                                             */

        int arr[setSize];
        int a;
        for(a=0; a<=setSize-1; a++)
        {
            cout << "Enter unique positive integer #" << a+1 << " for case " << caseCnt << ": ";
            cin >> arr[a];
        }


                                                                             /** Here, a bubble sort algorithm is used
                                                                             * to sort each case in order of its numerical
                                                                             * value. This will make it far easier to
                                                                             * implement the "cluster counter" algorithm
                                                                             * which will compare each consecutive
                                                                             * element and define their cluster based on
                                                                             * their values.
                                                                             * */
        int p, q;
        for(p=0; p<=setSize-2; p++)
        {
            for(q=p+1; q<=setSize-1; q++)
            {
                int holder;
                if(arr[p]>arr[q])
                {
                    holder = arr[p];
                    arr[p] = arr[q];
                    arr[q] = holder;
                }

            }
        }

        cout << "\nSorted Elements: " << endl;
        for(p=0; p<=setSize-1; p++)
        {
            cout << arr[p] << endl;
        }



                                                                                 /** The is the heart of the program ;).
                                                                                 * This algorithm snippet compares each
                                                                                 * element to the consecutive element,
                                                                                 * and each time their difference is
                                                                                 * greater than the parameter k, the
                                                                                 * "clusterNum" integer, which starts at
                                                                                 * one and counts how many clusters
                                                                                 * there are in each set of numbers,
                                                                                 * goes up by one, until the total
                                                                                 * number of clusters for each case is
                                                                                 * totaled up and outputted by the
                                                                                 * program
                                                                                 * */

        int i;
        for(i=0; i<=setSize-2; i++)
        {
            if( (arr[i+1]-arr[i]) > k)
            {
                clusterNum++;
            }
        }
        cout << "\nThere are " << clusterNum << " clusters in case " << caseCnt << endl;
    }
    return 0;
}


