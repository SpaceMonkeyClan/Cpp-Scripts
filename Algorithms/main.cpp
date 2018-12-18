// Bubble Sort Algorithm - V 1.0.0
// Author: Dena, Rene
// Last Modified: 3/23/18

//________________________________________Misc._____________________________________________________

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>


using namespace std;

//________________________________________Functions_________________________________________________


//________________________________________All Script________________________________________________

int main()
{
    //int num_Array[] = {};
    vector<int> num_Array;
    vector<int>::iterator pos;
    int user_Num;

    cout << "\n\n\t\t\tWelcome to the \"Bubble Sort Algorithm\"" << endl;
    cout << "\nThis program will sort an array containing numbers 1 from __: ";
    cin >> user_Num;

    for(int i=1; i <= user_Num; i++)
    {
        num_Array.push_back(i);
    }

    random_shuffle(num_Array.begin(), num_Array.end());

    cout << "\nAwesome! The list is as follows: ";
    for (pos=num_Array.begin(); pos!=num_Array.end(); ++pos)
    {
        cout << *pos << ' ';
    }

    int last_num = num_Array.back();
    for(int i = user_Num; last_num <= num_Array[i]; i--)


    return 0;
}
