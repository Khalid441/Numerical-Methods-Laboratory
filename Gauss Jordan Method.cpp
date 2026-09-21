#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int MAX = 20;

    char again;

    do
    {
        int n;
        double a[MAX][MAX + 1];
        double original[MAX][MAX + 1];

        cout << "Enter number of equations: ";
        cin >> n;

        cout << "Enter the augmented matrix:\n";

        // Input matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cin >> a[i][j];
                original[i][j] = a[i][j];
            }
        }

        // Gauss-Jordan Elimination
        for (int i = 0; i < n; i++)
        {
            // Find a non-zero pivot
            if (fabs(a[i][i]) < 0.000001)
            {
                for (int k = i + 1; k < n; k++)
                {
                    if (fabs(a[k][i]) > 0.000001)
                    {
                        for (int j = 0; j <= n; j++)
                        {
                            swap(a[i][j], a[k][j]);
                        }
                        break;
                    }
                }
            }

            // If pivot is still zero, skip it
            if (fabs(a[i][i]) < 0.000001)
                continue;

            // Make pivot = 1
            double pivot = a[i][i];

            for (int j = 0; j <= n; j++)
            {
                a[i][j] = a[i][j] / pivot;
            }

            // Make all other values in this column = 0
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    double factor = a[k][i];

                    for (int j = 0; j <= n; j++)
                    {
                        a[k][j] = a[k][j] - factor * a[i][j];
                    }
                }
            }

            // Display matrix
            cout << "\nAfter step " << i + 1 << ":\n";

            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c <= n; c++)
                {
                    cout << a[r][c] << "\t";
                }
                cout << endl;
            }
        }

        // Check for no solution
        bool noSolution = false;

        for (int i = 0; i < n; i++)
        {
            bool zeroRow = true;

            for (int j = 0; j < n; j++)
            {
                if (fabs(a[i][j]) > 0.000001)
                {
                    zeroRow = false;
                    break;
                }
            }

            if (zeroRow && fabs(a[i][n]) > 0.000001)
            {
                noSolution = true;
            }
        }

        if (noSolution)
        {
            cout << "\nThe system has no solution.\n";
        }
        else
        {
            // Find rank
            int rank = 0;

            for (int i = 0; i < n; i++)
            {
                bool nonZeroRow = false;

                for (int j = 0; j < n; j++)
                {
                    if (fabs(a[i][j]) > 0.000001)
                    {
                        nonZeroRow = true;
                        break;
                    }
                }

                if (nonZeroRow)
                    rank++;
            }

            if (rank < n)
            {
                cout << "\nThe system has infinite solution.\n";
            }
            else
            {
                cout << "\nThe system has unique solution.\n";

                // Print solutions
                cout << "\nSolution:\n";

                double x[MAX];

                for (int i = 0; i < n; i++)
                {
                    x[i] = a[i][n];

                    cout << "x" << i + 1 << " = "
                         << x[i] << endl;
                }

                // Verification
                cout << "\nVerification:\n";

                for (int i = 0; i < n; i++)
                {
                    double result = 0;

                    for (int j = 0; j < n; j++)
                    {
                        result = result + original[i][j] * x[j];
                    }

                    cout << "Equation " << i + 1 << ": ";
                    cout << result << " = " << original[i][n];

                    if (fabs(result - original[i][n]) < 0.000001)
                        cout << "  -> Satisfied";
                    else
                        cout << "  -> Not Satisfied";

                    cout << endl;
                }
            }
        }

        cout << "\nSolve another system? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
