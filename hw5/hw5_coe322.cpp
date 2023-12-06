// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 5
#include <iostream>
#include <cmath>
using namespace std;

// function to check if a number is prime
bool isprime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    for (int r = 2; r < 1000; r++) //loop to test if all the numbers from 2 to 1000 are prime
    {
        if (isprime(r))
        {
            for (int p = 2; p < r; p++)
            {
                if (isprime(p) && (r - p) % 2 == 0 && isprime((r - p) / 2))
                {
                    cout << r << " = " << p << " + " << (r - p) / 2 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}