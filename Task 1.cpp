#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
 {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess;
    const int maxAttempts = 10;
    int attempts = 0;
    cout << "Welcome to the Number Guessing Game!\n";
    for (attempts = 1; attempts <= maxAttempts; ++attempts) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
            break;
        }
    }

    if (attempts > maxAttempts) {
        cout << "Sorry, you've reached the maximum number of attempts. The correct number was: " << secretNumber << "\n";
    }

    return 0;
}