#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

class Lift {
private:
    int currentFloor;
    int targetFloor;
    bool doorsOpen;

public:
    Lift() : currentFloor(0), targetFloor(0), doorsOpen(false) {}

    void moveToFloor(int floor) {
        targetFloor = floor;
        simulateMovement();
        currentFloor = targetFloor;
        openDoors();
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate doors open for 2 seconds
        closeDoors();
    }

    int getCurrentFloor() const {
        return currentFloor;
    }

    bool areDoorsOpen() const {
        return doorsOpen;
    }

private:
    void simulateMovement() {
        if (currentFloor == targetFloor) {
            return;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate moving between floors
    }

    void openDoors() {
        doorsOpen = true;
    }

    void closeDoors() {
        doorsOpen = false;
    }
};

int main() {
    Lift lift;

    while (true) {
        system("cls"); // Clear the console (for Windows, use "clear" for Linux)
        
        // Display the lift and floor status
        std::cout << "********************  Lift Management  ********************" << std::endl;
        std::cout << "                     _____________                       " << std::endl;
        for (int i = 5; i >= 0; i--) { // Updated to start from floor 0 (Ground Floor)
            std::cout << "                    ";
            if (lift.getCurrentFloor() == i) {
                std::cout << "|  *  *  *  *  *  |  ";
            } else {
                std::cout << "|  ||  ||  ||  ||  |  ";
            }
            if (i == 0) { // Updated to display "Ground Floor" for floor 0
                std::cout << "Ground Floor";
            } else {
                std::cout << "Floor " << i;
            }
            if (lift.areDoorsOpen() && lift.getCurrentFloor() == i) {
                std::cout << " (Doors Open)";
            }
            std::cout << std::endl;
        }
        std::cout << "                    ";
        std::cout << "|  ||  ||  ||  ||  |  ";
        std::cout << "Lift ";
        if (lift.areDoorsOpen()) {
            std::cout << "(Doors Open)";
        } else {
            std::cout << "(Doors Closed)";
        }
        std::cout << std::endl;
        std::cout << "                    ";
        std::cout << "|__||__||__||__||__|  " << std::endl;
        std::cout << "**********************************************************" << std::endl;

        // User input to move the lift
        int targetFloor;
        std::cout << "Enter the floor number (0-5) to move the lift (0 to exit): ";
        std::cin >> targetFloor;

        if (targetFloor == 0) {
            break; // Exit the program
        }

        if (targetFloor < 0 || targetFloor > 5) { // Updated for ground floor
            std::cout << "Invalid floor. Please enter a floor number between 0 and 5." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            continue;
        }

        lift.moveToFloor(targetFloor);
    }

    return 0;
}

