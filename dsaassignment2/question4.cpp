#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int choice;
    char str1[100], str2[100], temp[100];
    char ch;

    do {
        cout << "\n--- String Related Programs ---\n";
        cout << "1. Concatenate one string to another\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete all vowels from a string\n";
        cout << "4. Sort strings in alphabetical order\n";
        cout << "5. Convert a character from uppercase to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer

        switch (choice) {
            case 1: {
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);

                int len1 = strlen(str1);
                for (int i = 0; str2[i] != '\0'; i++) {
                    str1[len1 + i] = str2[i];
                }
                str1[len1 + strlen(str2)] = '\0';
                cout << "Concatenated String: " << str1 << endl;
                break;
            }

            case 2: {
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                int n = strlen(str1);
                for (int i = 0; i < n / 2; i++) {
                    char temp = str1[i];
                    str1[i] = str1[n - i - 1];
                    str1[n - i - 1] = temp;
                }
                cout << "Reversed String: " << str1 << endl;
                break;
            }

            case 3: {
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                int j = 0;
                for (int i = 0; str1[i] != '\0'; i++) {
                    if (!isVowel(str1[i])) {
                        str1[j++] = str1[i];
                    }
                }
                str1[j] = '\0';
                cout << "String without vowels: " << str1 << endl;
                break;
            }

            case 4: {
                int n;
                cout << "Enter number of strings: ";
                cin >> n;
                cin.ignore();
                char arr[50][50];
                for (int i = 0; i < n; i++) {
                    cout << "Enter string " << i + 1 << ": ";
                    cin.getline(arr[i], 50);
                }

                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (strcmp(arr[i], arr[j]) > 0) {
                            strcpy(temp, arr[i]);
                            strcpy(arr[i], arr[j]);
                            strcpy(arr[j], temp);
                        }
                    }
                }

                cout << "Sorted Strings:\n";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << endl;
                }
                break;
            }

            case 5: {
                cout << "Enter an uppercase character: ";
                cin >> ch;
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch + 32;
                }
                cout << "Lowercase: " << ch << endl;
                break;
            }

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
