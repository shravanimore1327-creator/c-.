
#include <iostream>
using namespace std;

int main()
{
    int a[25], n, choice, num;
    int i, j, count;

    cout << "Enter how many numbers (1 to 25): ";
    cin >> n;

    if (n < 1 || n > 25)
    {
        cout << "Invalid number of elements!";
        return 0;
    }

    cout << "Enter " << n << " numbers:\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    do
    {
        cout << "\n------ MENU ------";
        cout << "\n1. Print first 5 even numbers";
        cout << "\n2. Print first 5 odd numbers";
        cout << "\n3. Print first 5 prime numbers";
        cout << "\n4. Check whether a number is prime or not";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                count = 0;
                cout << "First 5 even numbers:\n";

                for (i = 0; i < n && count < 5; i++)
                {
                    if (a[i] % 2 == 0)
                    {
                        cout << a[i] << " ";
                        count++;
                    }
                }

                if (count == 0)
                    cout << "No even numbers found.";
                else if (count < 5)
                    cout << "\nOnly " << count << " even numbers found.";
                break;

            case 2:
                count = 0;
                cout << "First 5 odd numbers:\n";

                for (i = 0; i < n && count < 5; i++)
                {
                    if (a[i] % 2 != 0)
                    {
                        cout << a[i] << " ";
                        count++;
                    }
                }

                if (count == 0)
                    cout << "No odd numbers found.";
                else if (count < 5)
                    cout << "\nOnly " << count << " odd numbers found.";
                break;

            case 3:
                count = 0;
                cout << "First 5 prime numbers:\n";

                for (i = 0; i < n && count < 5; i++)
                {
                    num = a[i];

                    if (num < 2)
                        continue;

                    int prime = 1;

                    for (j = 2; j <= num / j; j++)
                    {
                        if (num % j == 0)
                        {
                            prime = 0;
                            break;
                        }
                    }

                    if (prime == 1)
                    {
                        cout << num << " ";
                        count++;
                    }
                }

                if (count == 0)
                    cout << "No prime numbers found.";
                else if (count < 5)
                    cout << "\nOnly " << count << " prime numbers found.";
                break;

            case 4:
                cout << "Enter a number to check: ";
                cin >> num;

                if (num < 2)
                {
                    cout << num << " is not a prime number.";
                }
                else
                {
                    int prime = 1;

                    for (j = 2; j <= num / j; j++)
                    {
                        if (num % j == 0)
                        {
                            prime = 0;
                            break;
                        }
                    }

                    if (prime == 1)
                        cout << num << " is a prime number.";
                    else
                        cout << num << " is not a prime number.";
                }
                break;

            case 5:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice! Please try again.";
        }

    } while (choice != 5);

    return 0;
}
