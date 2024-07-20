#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Function to add two numbers
float add(float num1, float num2) {
    return num1 + num2;
}

// Function to subtract two numbers
float subtract(float num1, float num2) {
    return num1 - num2;
}

// Function to multiply two numbers
float multiply(float num1, float num2) {
    return num1 * num2;
}

// Function to divide two numbers
float divide(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

// Function to calculate square root
float calculateSqrt(float num) {
    if (num >= 0) {
        return sqrt(num);
    } else {
        cout << "Error: Square root of negative number!" << endl;
        return 0;
    }
}

// Function to calculate power
float power(float num1, float num2) {
    return pow(num1, num2);
}

// Function to calculate logarithm
float calculateLog(float num) {
    if (num > 0) {
        return log(num);
    } else {
        cout << "Error: Logarithm of non-positive number!" << endl;
        return 0;
    }
}

// Function to calculate sine
float calculateSin(float num) {
    return sin(num * M_PI / 180);
}

// Function to calculate cosine
float calculateCos(float num) {
    return cos(num * M_PI / 180);
}

// Function to calculate tangent
float calculateTan(float num) {
    return tan(num * M_PI / 180);
}

int main() {
    int choice;
    float num1, num2, result;

    cout << "Amazing Calculator" << endl;
    cout << "-----------------" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Square Root" << endl;
    cout << "6. Power" << endl;
    cout << "7. Logarithm" << endl;
    cout << "8. Sine" << endl;
    cout << "9. Cosine" << endl;
    cout << "10. Tangent" << endl;
    cout << "11. Exit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 11) {
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = add(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = subtract(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = multiply(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = divide(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 5:
                cout << "Enter a number: ";
                cin >> num1;
                result = calculateSqrt(num1);
                cout << "Result: " << result << endl;
                break;
            case 6:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = power(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 7:
                cout << "Enter a number: ";
                cin >> num1;
                result = calculateLog(num1);
                cout << "Result: " << result << endl;
                break;
            case 8:
                cout << "Enter a number: ";
                cin >> num1;
                result = calculateSin(num1);
                cout << "Result: " << result << endl;
                break;
            case 9:
                cout << "Enter a number: ";
                cin >> num1;
                result = calculateCos(num1);
                cout << "Result: " << result << endl;
                break;
            case 10:
                cout << "Enter a number: ";
                cin >> num1;
                result = calculateTan(num1);
                cout << "Result: " << result << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    return 0;
}
