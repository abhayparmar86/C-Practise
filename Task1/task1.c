// ----------------------------Now only one switch case is needed used function pass by value, and pass by refrence concept to pass different durations to single function

#include<stdio.h>
#include <unistd.h> 
#include<time.h>

int PH_RED_DURATION =10;
int PH_GREEN_DURATION=5;
int PH_YELLOW_DURATION= 2;
int NH_RED_DURATION= 5;
int NH_GREEN_DURATION= 5;  
int NH_YELLOW_DURATION= 2;

void redStateFunc(int);
void greenStateFunc(int);
void yellowStateFunc(int);
void tLight(int*,int*,int*);


typedef enum {
    RED,
    GREEN,
    YELLOW
} State;

typedef struct {
    State state;    
    int duration;   
}TrafficLight;

typedef union{
    void (*redState)(int duration);
    void(*greenState)(int duration);
    void(*yellowState)(int duration);
}StateMachine;

StateMachine machine;
TrafficLight light={RED,2};

int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
     
    int hour = timeinfo->tm_hour;

    while(1)
    {
        if((hour > 8 && hour < 13) ||  (hour > 18 && hour <21))
        {
            tLight(&PH_RED_DURATION,&PH_GREEN_DURATION,&PH_YELLOW_DURATION);
        }
        else
        {
            tLight(&NH_RED_DURATION,&NH_GREEN_DURATION,&NH_YELLOW_DURATION);
        }
    }
    return 0;
}
void tLight(int *RED_TIME,int *GREEN_TIME,int *YELLOW_TIME)
{
       switch(light.state){
            case RED:
                machine.redState = redStateFunc;
                light.duration = *RED_TIME;
                machine.redState(light.duration);
                break;

            case GREEN:
                machine.greenState = greenStateFunc;
                light.duration = *GREEN_TIME;
                machine.greenState(light.duration);
                break;
            
            case YELLOW:
                machine.yellowState = yellowStateFunc;
                light.duration = *YELLOW_TIME;
                machine.yellowState(light.duration);
                break;
        }
}


void redStateFunc(int duration)
{
    printf("RED Light: %d\n",duration);
    light.state=GREEN; 
    sleep(duration);
}

void greenStateFunc(int duration)
{
    printf("Green Light: %d\n",duration);
    light.state=YELLOW;
    sleep(duration);
}

void yellowStateFunc(int duration)
{
    printf("Yellow Light: %d\n",duration);
    light.state=RED;
    sleep(duration);
}

// ----------------------------------------------Used time library to get real time and hour, typecasted the hour using'atoi' function and than getting peak hours using ifelse condition.
// ----------------------------------------------It uses two switch cases

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h> // for sleep function
// #include <time.h>   // for time functions

// // states of the traffic light
// typedef enum
// {
//     RED,
//     GREEN,
//     YELLOW
// } State;

// // stucture for traffic light
// typedef struct
// {
//     State state : 8;
//     int duration : 8;
// } TrafficLight;

// void redStateFunc(int);
// void greenStateFunc(int);
// void yellowStateFunc(int);

// // union for the state machine functions
// typedef union
// {
//     void (*statefunctions[3])(int);

// } StateMachine;

// TrafficLight trafficlight;

// int main()
// {
//     // taking real time
//     /*time_t rawtime;
//     struct tm *timeinfo;
//     time(&rawtime);
//     timeinfo = localtime(&rawtime);
//     int hours = timeinfo->tm_hour;
//     int minutes = timeinfo->tm_min; */

//     char time[] = _TIME_;
//     char hour[3];
//     printf("current time hours\n");
//     for (int i = 0; i < 2; i++)
//     {
//         hour[i] = time[i];
//         printf("%c", time[i]);
//     }

//     hour[2] = '\0';
//     int hr = atoi(hour);
//     printf("\n%d\n", hr);

//     // printf("Current time: %02d:%02d\n", hours, minutes);
//     int flag;
//     if ((hr >= 8 && hr <= 10 || (hr >= 18 && hr <= 21)))
//     {
//         flag = 1;
//     }
//     else
//     {
//         flag = 0;
//     }

//     trafficlight.state = RED;
//     StateMachine statemachine;
//     statemachine.statefunctions[0] = redStateFunc;
//     statemachine.statefunctions[1] = greenStateFunc;
//     statemachine.statefunctions[2] = yellowStateFunc;

//     while (1)
//     {
//         if (flag)
//         {
//             switch (trafficlight.state)
//             {
//             case RED:
//                 trafficlight.duration = 11;
//                 statemachine.statefunctions[0](trafficlight.duration);
//                 break;

//             case GREEN:
//                 trafficlight.duration = 7;
//                 statemachine.statefunctions[1](trafficlight.duration);
//                 break;

//             case YELLOW:
//                 trafficlight.duration = 3;
//                 statemachine.statefunctions[2](trafficlight.duration);
//                 break;
//             }
//         }

//         else
//         {
//             switch (trafficlight.state)
//             {
//             case RED:
//                 trafficlight.duration = 8;
//                 statemachine.statefunctions[0](trafficlight.duration);
//                 break;

//             case GREEN:
//                 trafficlight.duration = 6;
//                 statemachine.statefunctions[1](trafficlight.duration);
//                 break;

//             case YELLOW:
//                 trafficlight.duration = 3;
//                 statemachine.statefunctions[2](trafficlight.duration);
//                 break;
//             }
//         }
//     }
//     return 0;
// }

// // state machine functions
// void redStateFunc(int duration)
// {
//     printf("RED Light: %d\n", duration);
//     trafficlight.state = GREEN;
//     sleep(duration);
// }

// void greenStateFunc(int duration)
// {
//     printf("Green Light: %d\n", duration);
//     sleep(duration);
//     trafficlight.state = YELLOW;
// }

// void yellowStateFunc(int duration)
// {
//     printf("Yellow Light: %d\n", duration);
//     sleep(duration);
//     trafficlight.state = RED;
// }

// ------------------Used Time library to compare time and get peak hours but not typecasted the hour so ifelse condition not working used structure for hour, min.

// #include<stdio.h>
// #include<string.h>
// #include <unistd.h> // for sleep function
// #include <time.h>   // for time functions

// //states of the traffic light
// typedef enum {
//     RED,
//     GREEN,
//     YELLOW
// } State;

// //stucture for traffic light
// typedef struct {
//     State state:8;
//     int duration:8;
// }TrafficLight;

// void redStateFunc(int);
// void greenStateFunc(int);
// void yellowStateFunc(int);

// //union for the state machine functions
// typedef union{
//     void (*statefunctions[3])(int);

// }StateMachine;

// TrafficLight trafficlight;

// int main()
// {
//     //taking real time
//     time_t rawtime;
//     struct tm *timeinfo;
//     time(&rawtime);
//     timeinfo = localtime(&rawtime);
//     int hours = timeinfo->tm_hour;
//     int minutes = timeinfo->tm_min;

//     printf("Current time: %02d:%02d\n", hours, minutes);
//     int flag;
//     if((hours>=8 && hours<11 || (hours>=18 && hours<21)))
//     {
//         flag=1;

//     }
//     else{
//        flag=0;
//     }

//     trafficlight.state=RED;
//     StateMachine statemachine;
//     statemachine.statefunctions[0]=redStateFunc;
//     statemachine.statefunctions[1]=greenStateFunc;
//     statemachine.statefunctions[2]=yellowStateFunc;

//     while(1)
//     {
//         if(flag==1){
//         switch(trafficlight.state){
//             case RED:
//                 trafficlight.duration=11;
//                 statemachine.statefunctions[0](trafficlight.duration);
//                 break;

//             case GREEN:
//                 trafficlight.duration=7;
//                 statemachine.statefunctions[1](trafficlight.duration);
//                 break;

//             case YELLOW:
//                 trafficlight.duration=3;
//                 statemachine.statefunctions[2](trafficlight.duration);
//                 break;
//         }

//         }

//         else{
//             switch(trafficlight.state){
//             case RED:
//                 trafficlight.duration=8;
//                 statemachine.statefunctions[0](trafficlight.duration);
//                 break;

//             case GREEN:
//                 trafficlight.duration=6;
//                 statemachine.statefunctions[1](trafficlight.duration);
//                 break;

//             case YELLOW:
//                 trafficlight.duration=3;
//                 statemachine.statefunctions[2](trafficlight.duration);
//                 break;
//         }
//         }
//     }
//     return 0;
// }

// //state machine functions
// void redStateFunc(int duration)
// {
//     printf("RED Light: %d\n",duration);
//     trafficlight.state=GREEN;
//     sleep(duration);

// }

// void greenStateFunc(int duration)
// {
//     printf("Green Light: %d\n",duration);
//     sleep(duration);
//     trafficlight.state=YELLOW;
// }

// void yellowStateFunc(int duration)
// {
//     printf("Yellow Light: %d\n",duration);
//     sleep(duration);
//     trafficlight.state=RED;
// }

// --------------------------------------------My code, Used enums, structures, and Function pointers for fixed times, no variable timings

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
// void redState(int *duration);
// void greenState(int *duration);
// void yellowState(int *duration);

// // Union for state function pointers
// typedef union {
//     // void (*stateFunc)(int duration);
//     void (*functions[3])(int *duration); // Array to hold all state functions
// } StateFunctions;

// int main() {
//     TrafficLight trafficLight = {RED, 2}; // Initialize traffic light to RED state with duration 10 seconds

//     // Define and initialize the union with state function pointers
//     StateFunctions stateFuncs;
//     stateFuncs.functions[0] = redState;
//     stateFuncs.functions[1] = greenState;
//     stateFuncs.functions[2] = yellowState;

//     while (1) {
//         stateFuncs.functions[trafficLight.state](&trafficLight.duration); // Call the appropriate state function
//         switch (trafficLight.state) {
//             case 0:
//                 trafficLight.state = 1;
//                 trafficLight.duration = 2;
//                 break;
//             case 1:
//                 trafficLight.state = 2;
//                 trafficLight.duration = 2;
//                 break;
//             case 2:
//                 trafficLight.state = 0;
//                 trafficLight.duration = 2;
//                 break;
//         }
//     }
//     return 0;
// }

// // State function implementations
// void redState(int *duration) {
//     printf("RED Light: %d\n", *duration);
//     sleep(*duration);
// }

// void greenState(int *duration) {
//     printf("Green Light: %d\n", *duration);
//     sleep(*duration);
// }

// void yellowState(int *duration) {
//     printf("Yellow Light: %d\n", *duration);
//     sleep(*duration);
// }

// -------------------------------------------------Mamta's code using unions, and function pointers fixed timings, not for peak hours

// // #include<stdio.h>
// // #include <unistd.h> // for sleep function

// // // Define the states of the traffic light
// // typedef enum {
// //     RED,
// //     GREEN,
// //     YELLOW
// // } State;

// // //Define the stucture for traffic light
// // typedef struct {
// //     State state;    //represents the current state of the traffic light
// //     int duration;   //represents the duration of current state
// // }TrafficLight;

// // //Define function prototypes
// // void redStateFunc(int duration);
// // void greenStateFunc(int duration);
// // void yellowStateFunc(int duration);

// // //Define union for the state machine functions
// // typedef union{
// //     void (*redState)(int duration);
// //     void(*greenState)(int duration);
// //     void(*yellowState)(int duration);
// // }StateMachine;

// // //Define state machine functions
// // void redStateFunc(int duration)
// // {
// //     printf("RED Light: %d\n",duration);
// //     sleep(duration);
// // }

// // void greenStateFunc(int duration)
// // {
// //     printf("Green Light: %d\n",duration);
// //     sleep(duration);
// // }

// // void yellowStateFunc(int duration)
// // {
// //     printf("Yellow Light: %d\n",duration);
// //     sleep(duration);
// // }

// // int main()
// // {
// //     TrafficLight trafficlight={RED,2};  //Initialize traffic light to RED state with duration 10 seconds
// //     StateMachine statemachine;

// //     while(1)
// //     {
// //         switch(trafficlight.state){
// //             case RED:
// //                 statemachine.redState = redStateFunc;
// //                 statemachine.redState(trafficlight.duration);
// //                 trafficlight.state=GREEN; //Transition to green state
// //                 trafficlight.duration=3;  //Setting duration for grren state
// //                 break;

// //             case GREEN:
// //                 statemachine.greenState = greenStateFunc;
// //                 statemachine.greenState(trafficlight.duration);
// //                 trafficlight.state=YELLOW; //Transition to yellow state
// //                 trafficlight.duration=2;  //Setting duration for yellow state
// //                 break;

// //             case YELLOW:
// //                 statemachine.yellowState = yellowStateFunc;
// //                 statemachine.yellowState(trafficlight.duration);
// //                 trafficlight.state=RED; //Transition to red state
// //                 trafficlight.duration=2;  //Setting duration for red state
// //                 break;

// //         }
// //     }
// //     return 0;
// // }