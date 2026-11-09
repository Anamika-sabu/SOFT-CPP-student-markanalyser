#include <iostream>
using namespace std;

void readMarks(int marks[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }
}

int findTotal(int marks[], int n)
{
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        total = total + marks[i];
    }

    return total;
}

double findAverage(int marks[], int n)
{
    int total = findTotal(marks, n);

    return (double)total / n;
}

int findHighest(int marks[], int n)
{
    int highest = marks[0];

    for(int i = 1; i < n; i++)
    {
        if(marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

int findLowest(int marks[], int n)
{
    int lowest = marks[0];

    for(int i = 1; i < n; i++)
    {
        if(marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}

int countPassed(int marks[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(marks[i] >= 40)
        {
            count++;
        }
    }

    return count;
}

void printReport(int marks[], int n)
{
    cout << "Total: " << findTotal(marks, n) << endl;
    cout << "Average: " << findAverage(marks, n) << endl;
    cout << "Highest: " << findHighest(marks, n) << endl;
    cout << "Lowest: " << findLowest(marks, n) << endl;

    int passed = countPassed(marks, n);

    cout << "Passed: " << passed << endl;
    cout << "Failed: " << n - passed << endl;
}

int main()
{
    int marks[100];
    int n;
    char choice;

    do
    {
        cout << "Enter number of students: ";
        cin >> n;

        while(n < 1 || n > 100)
        {
            cout << "Enter count between 1 and 100: ";
            cin >> n;
        }

        cout << "Enter marks:\n";

        readMarks(marks, n);

        printReport(marks, n);

        cout << "Repeat analysis? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}