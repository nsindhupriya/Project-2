#include <stdio.h>
#include <stdbool.h>

// Enumerations for FSM states
typedef enum {
    IDLE,
    PRE_TAKEOFF_CHECK,
    RAISE_GEAR,
    GEAR_UP,
    PRE_LANDING_CHECK,
    LOWER_GEAR,
    GEAR_DOWN
} FSM_State;

// Function prototypes
void checkTakeoffConditions();
void raiseGear();
void lowerGear();
void checkLandingConditions();

// Variables
FSM_State currentState = IDLE;
bool squatSwitchOpen = false;
bool limitSwitchNose = false;
bool limitSwitchLeft = false;
bool limitSwitchRight = false;
bool pilotLeverUp = false;
bool pilotLeverDown = false;

void updateState() {
    switch (currentState) {
        case IDLE:
            if (pilotLeverUp) {
                currentState = PRE_TAKEOFF_CHECK;
                // Turn lights RED, Set direction valve UP
                printf("Lights RED, Direction valve UP\n");
            }
            if (pilotLeverDown) {
                currentState = PRE_LANDING_CHECK;
                // Turn lights RED, Set direction valve DOWN
                printf("Lights RED, Direction valve DOWN\n");
            }
            break;

        case PRE_TAKEOFF_CHECK:
            checkTakeoffConditions();
            break;

        case RAISE_GEAR:
            raiseGear();
            break;

        case GEAR_UP:
            // Gear up state logic
            break;

        case PRE_LANDING_CHECK:
            checkLandingConditions();
            break;

        case LOWER_GEAR:
            lowerGear();
            break;

        case GEAR_DOWN:
            // Gear down state logic
            break;
    }
}

void checkTakeoffConditions() {
    // Logic to check squat switch and timer for 4 seconds
    if (squatSwitchOpen) {
        currentState = RAISE_GEAR;
        // Start raising gear
        printf("Raising Gear\n");
    } else {
        // Stay in pre-takeoff check state
    }
}

void raiseGear() {
    // Logic to raise gear
    if (limitSwitchNose && limitSwitchLeft && limitSwitchRight) {
        currentState = GEAR_UP;
        // Turn lights OFF, Disable landing gear control
        printf("Lights OFF, Control disabled\n");
    } else {
        // Keep raising gear
    }
}

void lowerGear() {
    // Logic to lower gear
    if (!limitSwitchNose && !limitSwitchLeft && !limitSwitchRight) {
        currentState = GEAR_DOWN;
        // Turn lights GREEN
        printf("Lights GREEN\n");
    } else {
        // Keep lowering gear
    }
}

void checkLandingConditions() {
    // Logic to check landing conditions
    currentState = LOWER_GEAR;
    // Start lowering gear
    printf("Lowering Gear\n");
}

int main() {
    // Example of state transition
    pilotLeverUp = true;  // Simulating pilot's lever up action
    updateState();
    squatSwitchOpen = true;  // Simulating squat switch open
    updateState();
    limitSwitchNose = true;
    limitSwitchLeft = true;
    limitSwitchRight = true;
    updateState();
    return 0;
}




