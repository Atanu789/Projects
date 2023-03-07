#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator with the current time
    int secretNumber = rand() % 100 + 1;  // Generate a balchal number between 1 and 100
    int guess, numAttempts = 0;
    const int MAX_ATTEMPTS = 8;  // Maximum number of attempts allowed

    cout << "Welcome to the Guess the Number Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100. You have " << MAX_ATTEMPTS << " attempts to guess it." << endl;

    while (numAttempts < MAX_ATTEMPTS) {
        cout << "Enter your guess: ";
        cin >> guess;
        numAttempts++;

        if (guess == secretNumber) {
            cout << "Congratulations, Bara you guessed the number in " << numAttempts << " attempts!" << endl;
            return 0;  // Exit the program
        } else if (guess < secretNumber) {
            cout << "Pagolchoda too low. ";
        } else {
            cout << "Khepachoda Too high. ";
        }

        cout << "You have " << MAX_ATTEMPTS - numAttempts << " attempts remaining." << endl;
    }

    cout << "Haat, kya gunda banega re tu! The number was " << secretNumber << "." << endl;

    return 0;
}
