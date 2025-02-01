#include <iostream>
#include <string>
using namespace std;

int main() {
    char direction;
    cin >> direction;

    string typedMessage;
    cin >> typedMessage;

    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string originalMessage = "";

    for (char ch : typedMessage) {
        size_t index = keyboard.find(ch);
        if (direction == 'R') {
            originalMessage += keyboard[index - 1];
        } else if (direction == 'L') {
            originalMessage += keyboard[index + 1];
        }
    }

    cout << originalMessage << endl;

    return 0;
}
