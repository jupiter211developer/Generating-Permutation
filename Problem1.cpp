// Problem1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

using namespace std;

void funcForAlgorithm1(int n)
{
    int* a = new int[n];
    cout << "Algorithm 1" << endl;

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            int k = rand() % n + 1, j;
            for (j = 0; j < i; j++)
            {
                if (a[j] == k)
                {
                    break;
                }
            }

            if (j == i)
            {
                a[i] = k;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl << endl;
    delete[] a;
}

void funcForAlgorithm2(int n)
{
    int* a = new int[n];
    int* used = new int[n + 1];

    memset(used, 0, 4 * (n + 1));
    cout << "Algorithm 2" << endl;

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            int k = rand() % n + 1;
            
            if (!used[k])
            {
                a[i] = k;
                used[k] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl << endl;
    delete[] a;
    delete[] used;
}

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void funcForAlgorithm3(int n)
{
    int* a = new int[n];

    cout << "Algorithm 3" << endl;

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    for (int i = 1; i < n; i++)
    {
        swap(a[i], a[rand() % i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl << endl;
    delete[] a;
}

int main()
{
    int n;

    cout << "Please Input length of permutation: ";
    cin >> n;

    srand((unsigned int)time(NULL));
    funcForAlgorithm1(n);
    funcForAlgorithm2(n);
    funcForAlgorithm3(n);
}

/*
* Project Description (permutation generating)
* 
* A. Prove that all three algorithms generate only legal permutations and that all permutationsare equally likely.
* 
*   algorithm 1: According to its process, there can't be duplicate elements. 
*                  We generate random numbers in range[1, n], there are no duplicates
*                  so, there are any missing elements. So it's @@@legal permutation@@@.
*               Each step generating elements depend on random, so all permutations are equally likely.
*   algorithm 2: it's same as algorithm 1, except that it's using *used* array.
*   algorithm 3: According to its process, elements in array are preserved while swapping.
*                   So, at first there are 1~n elements, there can't be any duplicates or missing.
*                   Every elements can go into any position, because swap position uses random, so all permutations are equally likely.
* 
* B. Give as accurate (Big-O) an analysis as you can of the expected runtime of each algorithm.
*   algorithm 1: O(C*n^2)
*   algorithm 2: O(C*n)
*   algorithm 3: O(n)
* 
*   C means constant(it can be eliminated).
* 
* C. Write (separate) programs to execute each algorithm to make sure they are working correctly. (This is not an actual proof!)
*   I have implemented.
* 
* D. What is the worst case runtime of each algorithm? Justify your answer
*   algorithm 1: O(C*n^2)
*                   In this algorithm, c means that count of generating randoms guranteeing the duplicates.
*                   C can be over n.
*                   In worst case, it can be O(n^3) and above.
*   algorithm 2: O(C*n)
*                   In this algorithm, c means that count of generating randoms guranteeing the duplicates.
* 
*   algorithm 3: O(n)
*                   In this algorithm, there's no specific worst case. They are equal everytime.
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
