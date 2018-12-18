// Honoi Tower Script - V 1.0.0
// Author: team effort
// Last Modified: 3/10/18

//________________________________________Misc._____________________________________________________

#include <iostream>

using namespace std;

//________________________________________Functions_________________________________________________


void Move(char F, char T, char E, int n)
{
    if(n==1)
    {
        cout << "Transfer Ring " << n << " from Tower " << F << " to Tower " << T << endl;
        return;
    }
    Move(F,E,T,n-1);
    cout << "Transfer Ring " << n << " from Tower " << F << " to Tower " << T << endl;
    Move(E, T, F, n-1);
    return;
}

//________________________________________All Script________________________________________________

int main()
{   int N;
    char A = 'a', B = 'b', C = 'c';
    cout<<"Enter the number of rings: ";
    cin >> N;
    Move(A, B, C, N);

    return 0;
}
