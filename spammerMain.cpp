#include <windows.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    std::string x;
    std::cout << "Please enter the message you would like spammed (it will be automatically followed by two newlines): ";
    std::getline(std::cin, x);

    x += "\n\n";
    int delayMs = 1;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    while (true) {
        for (char c : x) {
            SHORT vk = VkKeyScan(c);
            bool shift = (vk & 0x0100) != 0;
            BYTE key = LOBYTE(vk);

            if (shift) keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(key, 0, 0, 0);
            keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
            if (shift) keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);

            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }
    }

    return 0;
}
