#include <stdio.h>
#include <unistd.h> // for sleep function

// Define the states of the traffic light
typedef enum {
    RED, GREEN, YELLOW
} State;

// Define the traffic light structure
typedef struct {
    State state;
    int duration;
} TrafficLight;

// Function prototypes
void redState(int duration);
void greenState(int duration);
void yellowState(int duration);

// Union for state function pointers
typedef union {
    void (*stateFunc)(int duration);
    void (*functions[3])(int duration); // Array to hold all state functions
} StateFunctions;

int main() {
    TrafficLight trafficLight = {RED, 2}; // Initialize traffic light to RED state with duration 10 seconds
    
    // Define and initialize the union with state function pointers
    StateFunctions stateFuncs;
    stateFuncs.functions[RED] = redState;
    stateFuncs.functions[GREEN] = greenState;
    stateFuncs.functions[YELLOW] = yellowState;
    
    while (1) {
        stateFuncs.functions[trafficLight.state](trafficLight.duration); // Call the appropriate state function
        switch (trafficLight.state) {
            case RED:
                trafficLight.state = GREEN;
                trafficLight.duration = 2;
                break;
            case GREEN:
                trafficLight.state = YELLOW;
                trafficLight.duration = 2;
                break;
            case YELLOW:
                trafficLight.state = RED;
                trafficLight.duration = 2;
                break;
        }
    }
    return 0;
}

// State function implementations
void redState(int duration) {
    printf("RED Light: %d\n", duration);
    sleep(duration);
}

void greenState(int duration) {
    printf("Green Light: %d\n", duration);
    sleep(duration);
}

void yellowState(int duration) {
    printf("Yellow Light: %d\n", duration);
    sleep(duration);
}




// #include <stdio.h>
// #include <unistd.h> // for sleep function

// // Define the states of the traffic light
// typedef enum {
//     RED, GREEN, YELLOW
// } State;

// // Define the traffic light structure
// typedef struct {
//     State state;
//     int duration;
// } TrafficLight;

// // Function prototypes
// void stateFunc(State state, int duration);

// int main() {
//     TrafficLight trafficLight = {RED, 2}; // Initialize traffic light to RED state with duration 10 seconds
    
//     while (1) {
//         stateFunc(trafficLight.state, trafficLight.duration);
//         switch (trafficLight.state) {
//             case RED:
//                 trafficLight.state = GREEN;
//                 trafficLight.duration = 3;
//                 break;
//             case GREEN:
//                 trafficLight.state = YELLOW;
//                 trafficLight.duration = 2;
//                 break;
//             case YELLOW:
//                 trafficLight.state = RED;
//                 trafficLight.duration = 2;
//                 break;
//         }
//     }
//     return 0;
// }

// // Function to print the current state and sleep for the given duration
// void stateFunc(State state, int duration) {
//     switch (state) {
//         case RED:
//             printf("RED Light: %d\n", duration);
//             break;
//         case GREEN:
//             printf("Green Light: %d\n", duration);
//             break;
//         case YELLOW:
//             printf("Yellow Light: %d\n", duration);
//             break;
//     }
//     sleep(duration);
// }




// #include<stdio.h>
// #include <unistd.h> // for sleep function

// // Define the states of the traffic light
// typedef enum {
//     RED,
//     GREEN,
//     YELLOW
// } State;

// //Define the stucture for traffic light
// typedef struct {
//     State state;    //represents the current state of the traffic light
//     int duration;   //represents the duration of current state
// }TrafficLight;

// //Define function prototypes
// void redStateFunc(int duration);
// void greenStateFunc(int duration);
// void yellowStateFunc(int duration);

// //Define union for the state machine functions
// typedef union{
//     void (*redState)(int duration);
//     void(*greenState)(int duration);
//     void(*yellowState)(int duration);
// }StateMachine;

// //Define state machine functions
// void redStateFunc(int duration)
// {
//     printf("RED Light: %d\n",duration);
//     sleep(duration);
// }

// void greenStateFunc(int duration)
// {
//     printf("Green Light: %d\n",duration);
//     sleep(duration);
// }

// void yellowStateFunc(int duration)
// {
//     printf("Yellow Light: %d\n",duration);
//     sleep(duration);
// }

// int main()
// {
//     TrafficLight trafficlight={RED,2};  //Initialize traffic light to RED state with duration 10 seconds
//     StateMachine statemachine;

//     while(1)
//     {
//         switch(trafficlight.state){
//             case RED:
//                 statemachine.redState = redStateFunc;
//                 statemachine.redState(trafficlight.duration);
//                 trafficlight.state=GREEN; //Transition to green state
//                 trafficlight.duration=3;  //Setting duration for grren state
//                 break;

//             case GREEN:
//                 statemachine.greenState = greenStateFunc;
//                 statemachine.greenState(trafficlight.duration);
//                 trafficlight.state=YELLOW; //Transition to yellow state
//                 trafficlight.duration=2;  //Setting duration for yellow state
//                 break;
            
//             case YELLOW:
//                 statemachine.yellowState = yellowStateFunc;
//                 statemachine.yellowState(trafficlight.duration);
//                 trafficlight.state=RED; //Transition to red state
//                 trafficlight.duration=2;  //Setting duration for red state
//                 break;


//         }
//     }
//     return 0;
// }